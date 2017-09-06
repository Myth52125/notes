
#include <codebase/base/File.h>


using namespace myth52125;
using namespace myth52125::base;




LogFile::LogFile()
	：
{

}



void LogFile::append(const StringArg str,size_t len)
{
	if(_mutex)
	{
		MutexLockGuard look(_mutex);
		appendUnsafe(str,len);
	}else{
		appendUnsafe(str,len);
	}
}

void LogFile::appendUnsafe(const StringArg str ,size_t len)
{
	_file->append(str,len);
	_count ++;
	if(_file->written() > _maxSize || _count > _maxCount)
	{
		rollFile();
		_count = 0;	
	}
}

void LogFile::rollFile()
{
	StringArg nextFile = createNextFileName(_baseName);
	_file.reset(new File(nextFile));
}

StringArg LogFile::createNextFileName()
{
	//写完timeStamp 再来写
	return StringArg("newLog");

}



