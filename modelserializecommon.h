#pragma once

#include <QMap>
#include <QMetaType>
#include <QMetaProperty>
#include <QStringList>

typedef QMap<QString, QObject*> QObjectMap;

// for serializing
Q_DECLARE_METATYPE(QObjectList)
Q_DECLARE_METATYPE(QObjectMap)

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
// F is a tuple: (QMetaType::TypeName, QMetaType::TypeNameID, RealType)
// 'SChar' : is not a member of 'QMetaType'
#define QT_FOR_EACH_STATIC_PRIMITIVE_TYPE(F)\
	F(Void, 43, void) \
	F(Bool, 1, bool) \
	F(Int, 2, int) \
	F(UInt, 3, uint) \
	F(LongLong, 4, qlonglong) \
	F(ULongLong, 5, qulonglong) \
	F(Double, 6, double) \
	F(Long, 129, long) \
	F(Short, 130, short) \
	F(Char, 131, char) \
	F(ULong, 132, ulong) \
	F(UShort, 133, ushort) \
	F(UChar, 134, uchar) \
	F(Float, 135, float)
#endif

namespace utilities
{

const char kClassNameAttribute[] = "className";
const char kKeyValueAttribute[] = "keyValue";
const char kObjectIdAttribute[] = "objectId";
const char kObjectNameProperty[] = "objectName";

} // namespace utilities

