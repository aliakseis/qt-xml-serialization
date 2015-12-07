#ifndef TESTMODEL_H
#define TESTMODEL_H

#include "iparentadvice.h"

#include <QObject>

#include <utility>

#define DECLARE_Q_PROPERTY(prop, read, write) \
    public: \
	prop() const { return read##_; } \
	void write(prop) { read##_ = std::move(read); } \
    private: \
    prop##_;

#define DECLARE_Q_PROPERTY_ADAPTOR(params) DECLARE_Q_PROPERTY params

class SimpleElement : public QObject, public IParentAdvice
{
    Q_OBJECT

public:
    SimpleElement(QObject *parent = nullptr);
    ~SimpleElement();

#ifndef Q_MOC_RUN
    #define READ ,
    #define WRITE ,
    #undef Q_PROPERTY
    #define Q_PROPERTY(...) DECLARE_Q_PROPERTY_ADAPTOR((__VA_ARGS__))
#endif // Q_MOC_RUN

    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString url READ url WRITE setUrl)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(int viewCount READ viewCount WRITE setViewCount)
    Q_PROPERTY(int duration READ duration WRITE setDuration)

#undef Q_PROPERTY
#define Q_PROPERTY(text)
#undef READ
#undef WRITE

private:
    void setAdviceParent(QObject* parent) override
    {
        setParent(parent);
    }
};


class TestModel : public QObject
{
    Q_OBJECT

public:
    TestModel(QObject *parent = nullptr);
    ~TestModel();

#ifndef Q_MOC_RUN
    #define READ ,
    #define WRITE ,
    #undef Q_PROPERTY
    #define Q_PROPERTY(...) DECLARE_Q_PROPERTY_ADAPTOR((__VA_ARGS__))
#endif // Q_MOC_RUN

    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(QString title READ title WRITE setTitle)

#undef Q_PROPERTY
#define Q_PROPERTY(text)
#undef READ
#undef WRITE

    Q_PROPERTY(QObjectList entities READ entities WRITE setEntities)

public:
    QList<SimpleElement*> elements() const  { return m_elements; }
    void addElement(SimpleElement* element) 
    { 
        m_elements.push_back(element); 
        element->setParent(this);
    }

private:
    QObjectList entities() const;
    void setEntities(const QObjectList& ents);

    QList<SimpleElement*> m_elements;
};


#endif // TESTMODEL_H
