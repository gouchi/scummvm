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

#ifndef POSIX_FILESYSTEM_H
#define POSIX_FILESYSTEM_H

#include "backends/fs/abstract-fs.h"

#ifdef MACOSX
#include <sys/types.h>
#endif
#include <unistd.h>

#ifdef PLAYSTATION3
#define FORBIDDEN_SYMBOL_ALLOW_ALL
#define	F_OK		0	/* test for existence of file */
#define	W_OK		0x02	/* test for write permission */
#define	R_OK		0x04	/* test for read permission */


#ifndef S_ISDIR
#define S_ISDIR(x) (x & 0040000)
#endif

static inline int access(const char *pn, int mode)
{
   int fd = open(pn, O_RDONLY);
   if (fd < 0)
      return -1;

   // XXX lie about it, for now..
   close(fd);
   return 0;
}

static inline char *getenv(const char *name)
{
   return (char*)"/";
}
#endif

/**
 * Implementation of the ScummVM file system API based on POSIX.
 *
 * Parts of this class are documented in the base interface class, AbstractFSNode.
 */
class POSIXFilesystemNode : public AbstractFSNode {
protected:
	Common::String _displayName;
	Common::String _path;
	bool _isDirectory;
	bool _isValid;

	virtual AbstractFSNode *makeNode(const Common::String &path) const {
		return new POSIXFilesystemNode(path);
	}

	/**
	 * Plain constructor, for internal use only (hence protected).
	 */
	POSIXFilesystemNode() : _isDirectory(false), _isValid(false) {}

public:
	/**
	 * Creates a POSIXFilesystemNode for a given path.
	 *
	 * @param path the path the new node should point to.
	 */
	POSIXFilesystemNode(const Common::String &path);

	virtual bool exists() const { return access(_path.c_str(), F_OK) == 0; }
	virtual Common::String getDisplayName() const { return _displayName; }
	virtual Common::String getName() const { return _displayName; }
	virtual Common::String getPath() const { return _path; }
	virtual bool isDirectory() const { return _isDirectory; }
	virtual bool isReadable() const { return access(_path.c_str(), R_OK) == 0; }
	virtual bool isWritable() const { return access(_path.c_str(), W_OK) == 0; }

	virtual AbstractFSNode *getChild(const Common::String &n) const;
	virtual bool getChildren(AbstractFSList &list, ListMode mode, bool hidden) const;
	virtual AbstractFSNode *getParent() const;

	virtual Common::SeekableReadStream *createReadStream();
	virtual Common::WriteStream *createWriteStream();

private:
	/**
	 * Tests and sets the _isValid and _isDirectory flags, using the stat() function.
	 */
	virtual void setFlags();
};

#endif
