#include "testmodel.h"

#include "instantiator.h"


REGISTER_QOBJECT_METATYPE(SimpleElement)

SimpleElement::SimpleElement(QObject *parent)
    : QObject(parent)
{

}

SimpleElement::~SimpleElement()
{

}


REGISTER_QOBJECT_METATYPE(TestModel)

TestModel::TestModel(QObject *parent)
: QObject(parent)
{

}

TestModel::~TestModel()
{

}

QObjectList TestModel::entities() const
{
    QObjectList result;
    result.reserve(m_elements.size());
    std::copy(m_elements.begin(), m_elements.end(), std::back_inserter(result));
    return result;
}

void TestModel::setEntities(const QObjectList& ents)
{
    qDeleteAll(m_elements);
    m_elements.clear();
    m_elements.reserve(ents.size());
    Q_FOREACH(QObject * item, ents)
    {
        m_elements.push_back(static_cast<SimpleElement*>(item));
    }
}
