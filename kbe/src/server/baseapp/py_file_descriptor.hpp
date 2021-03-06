/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __PY_FILE_DESCRIPTOR__
#define __PY_FILE_DESCRIPTOR__

#include "cstdkbe/cstdkbe.hpp"
#include "pyscript/scriptobject.hpp"
#include "cstdkbe/smartpointer.hpp"

namespace KBEngine{
typedef SmartPointer<PyObject> PyObjectPtr;

class PyFileDescriptor : public Mercury::InputNotificationHandler
{
public:
	PyFileDescriptor(int fd, PyObject* pyCallback, bool write);
	virtual ~PyFileDescriptor();
	
	/** 
		�ű�����(ע��/ע��)�ļ�������(����д)
	*/
	static PyObject* __py_registerFileDescriptor(PyObject* self, PyObject* args);
	static PyObject* __py_registerWriteFileDescriptor(PyObject* self, PyObject* args);
	static PyObject* __py_deregisterFileDescriptor(PyObject* self, PyObject* args);
	static PyObject* __py_deregisterWriteFileDescriptor(PyObject* self, PyObject* args);
protected:

	virtual int handleInputNotification( int fd );
	
	void callback();

	int fd_;
	PyObjectPtr pyCallback_;

	bool write_;
};

}
#endif
