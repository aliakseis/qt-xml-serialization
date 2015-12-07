
#include <QtCore/QCoreApplication>

#include <QTemporaryFile>
#include <QXmlStreamWriter>

#include "testmodel.h"
#include "customutf8codec.h"
#include "modelserializer.h"
#include "modeldeserializer.h"

const char documentNodeName[] = "document";

enum { NUM_ELEMENTS = 10000 };

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestModel sourceModel;
    sourceModel.setId("42");
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        SimpleElement* element = new SimpleElement();
        element->setViewCount(i * 2);
        element->setDuration(i + 1);
        sourceModel.addElement(element);
    }

    TestModel replicaModel;

    QTemporaryFile file;

    if (file.open())
    {
        QXmlStreamWriter stream(&file);

        stream.setCodec(utilities::CustomUtf8Codec::Instance());

        stream.setAutoFormatting(true);
        stream.writeStartDocument();

        utilities::ModelSerializer serializer(stream);
        serializer.serialize(&sourceModel, documentNodeName);

        stream.writeEndDocument();
        const bool failed = stream.hasError();

        file.seek(0);

        QXmlStreamReader reader(&file);

        utilities::ModelDeserializer deserializer(reader);
        deserializer.deserialize(&replicaModel, documentNodeName);

        file.remove();
    }

    //return a.exec();
}
