/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "titanic/support/movie.h"
#include "titanic/support/avi_surface.h"
#include "titanic/sound/sound_manager.h"
#include "titanic/messages/messages.h"
#include "titanic/titanic.h"

namespace Titanic {

#define CLIP_WIDTH 600
#define CLIP_WIDTH_REDUCED (CLIP_WIDTH / 2)
#define CLIP_HEIGHT 340
#define CLIP_HEIGHT_REDUCED (CLIP_HEIGHT / 2)

CMovieList *CMovie::_playingMovies;
CVideoSurface *CMovie::_movieSurface;

CMovie::CMovie() : ListItem(), _state(MSTATE_0), _field10(0),
		_field14(0) {
}

CMovie::~CMovie() {
	removeFromPlayingMovies();
}

void CMovie::init() {
	_playingMovies = new CMovieList();
	_movieSurface = nullptr;
}

void CMovie::deinit() {
	delete _playingMovies;
	delete _movieSurface;
}

void CMovie::addToPlayingMovies() {
	if (!isActive())
		_playingMovies->push_back(this);
}

void CMovie::removeFromPlayingMovies() {
	_playingMovies->remove(this);
}

bool CMovie::isActive() const {
	return _playingMovies->contains(this);
}

bool CMovie::get10() {
	if (_field10) {
		_field10 = 0;
		return true;
	} else {
		return false;
	}
}

/*------------------------------------------------------------------------*/

OSMovie::OSMovie(const CResourceKey &name, CVideoSurface *surface) :
		_aviSurface(name), _videoSurface(surface) {
	_field18 = 0;
	_field24 = 0;
	_field28 = 0;
	_field2C = 0;
	_ticksStart = 0;
	_frameTime1 = 0;
	_frameTime2 = 17066;

	surface->resize(_aviSurface.getWidth(), _aviSurface.getHeight());
	_aviSurface.setVideoSurface(surface);
}

OSMovie::~OSMovie() {
}

void OSMovie::play(uint flags, CGameObject *obj) {
	_aviSurface.play(flags, obj);

	if (_aviSurface._isPlaying)
		movieStarted();
}

void OSMovie::play(uint startFrame, uint endFrame, uint flags, CGameObject *obj) {
	_aviSurface.play(startFrame, endFrame, flags, obj);

	if (_aviSurface._isPlaying)
		movieStarted();
}

void OSMovie::play(uint startFrame, uint endFrame, uint initialFrame, uint flags, CGameObject *obj) {
	_aviSurface.play(startFrame, endFrame, initialFrame, flags, obj);

	if (_aviSurface._isPlaying)
		movieStarted();
}

void OSMovie::playClip(const Point &drawPos, uint startFrame, uint endFrame) {
	if (!_movieSurface)
		_movieSurface = CScreenManager::_screenManagerPtr->createSurface(600, 340);
	
	bool widthLess = _videoSurface->getWidth() < 600;
	bool heightLess = _videoSurface->getHeight() < 340;
	Rect r(drawPos.x, drawPos.y,
		drawPos.x + widthLess ? CLIP_WIDTH_REDUCED : CLIP_WIDTH,
		drawPos.y + heightLess ? CLIP_HEIGHT_REDUCED : CLIP_HEIGHT
	);

	uint timePerFrame = 1000 / _aviSurface._frameRate;

	for (; endFrame >= startFrame; ++startFrame) {
		// Set the frame
		_aviSurface.setFrame(startFrame);

		// TODO: See if we need to do anything further here. The original had a bunch
		// of calls and using of the _movieSurface; perhaps to allow scaling down
		// videos to half-size
		if (widthLess || heightLess)
			warning("Not properly reducing clip size: %d %d", r.width(), r.height());

		// Wait for the next frame, unless the user interrupts the clip
		if (g_vm->_events->waitForPress(timePerFrame))
			break;
	}
}

void OSMovie::stop() {
	_aviSurface.stop();
	removeFromPlayingMovies();
}

void OSMovie::addEvent(int frameNumber, CGameObject *obj) {
	if (_aviSurface.addEvent(frameNumber, obj)) {
		CMovieFrameMsg frameMsg(frameNumber, 0);
		frameMsg.execute(obj);
	}
}

void OSMovie::setFrame(uint frameNumber) {
	_aviSurface.setFrame(frameNumber);
	_videoSurface->setMovieFrameSurface(_aviSurface.getSecondarySurface());
}

bool OSMovie::handleEvents(CMovieEventList &events) {
	if (!_aviSurface._isPlaying)
		return false;

	int time = (g_vm->_events->getTicksCount() + ((_ticksStart << 24) - _ticksStart)) << 8;
	if (time < _frameTime1)
		return _aviSurface._isPlaying;

	if (!_field14 && (time - _frameTime1) > (_frameTime2 * 2))
		_frameTime1 = time;

	_frameTime1 += _frameTime2;
	_aviSurface.handleEvents(events);
	_videoSurface->setMovieFrameSurface(_aviSurface.getSecondarySurface());

	if (_field14) {
		while (_frameTime1 >= time && events.empty()) {
			_aviSurface.handleEvents(events);
			_videoSurface->setMovieFrameSurface(_aviSurface.getSecondarySurface());

			_frameTime1 += _frameTime2;
		}
	}

	return _aviSurface._isPlaying;
}

const CMovieRangeInfoList *OSMovie::getMovieRangeInfo() const {
	return _aviSurface.getMovieRangeInfo();
}

void OSMovie::setSoundManager(CSoundManager *soundManager) {
	_aviSurface._soundManager = soundManager;
}

int OSMovie::getFrame() const {
	return _aviSurface.getFrame();
}

void OSMovie::movieStarted() {
	_frameTime1 = _frameTime2 = 256000.0 / _aviSurface._frameRate;
	_ticksStart = g_vm->_events->getTicksCount();

	if (_aviSurface._hasAudio)
		_aviSurface._soundManager->movieStarted();

	// Register the movie in the playing list
	addToPlayingMovies();
	_field10 = 1;
}

void OSMovie::setFrameRate(double rate) {
	_aviSurface.setFrameRate(rate);
}

Graphics::ManagedSurface *OSMovie::duplicateFrame() const {
	return _aviSurface.duplicateSecondaryFrame();
}

} // End of namespace Titanic
