
# Qt XML Serialization

This project provides a lightweight C++/Qt framework for serializing and deserializing QObject‑based models to and from XML.  
It is intended to integrate cleanly with Qt's meta‑object system, requiring minimal boilerplate while supporting nested object graphs, custom codecs, and flexible serialization rules.

## 🚀 Features

- **Automatic XML serialization/deserialization** for QObject‑derived classes  
- Uses **Qt meta‑object reflection** (properties, enums, object trees)  
- **ModelSerializer / ModelDeserializer** classes for saving and loading  
- **Custom UTF‑8 codec** implementation for improved XML encoding handling  
- **Patricia trie** utilities (used internally for fast lookup)  
- **Parent–child object graph support** via interfaces such as `IParentAdvice`  
- **Cross‑platform**: works with Qt 5 and Qt 6  
- Includes:
  - `.pro` and `.pri` files for qmake  
  - `.sln` and `.vcxproj` for MSVC/Windows builds

---

## 📂 Project Structure

```
qt-xml-serialization-master/
├── customutf8codec.*            # Custom UTF-8 text codec (QTextCodec)
├── instantiator.h               # Generic object instantiator using Qt meta‑types
├── iparentadvice.h              # Interface for advising parent relationships
├── modelserializer.*            # Core XML writer
├── modeldeserializer.*          # Core XML reader
├── modelserializecommon.*       # Shared helpers/utilities
├── patricia.h                   # Patricia trie implementation
├── testmodel.*                  # Example model demonstrating usage
├── main.cpp                     # Minimal sample application
├── qt-xml-serialization.pro     # qmake project file
├── qt-xml-serialization.pri     # qmake include
└── Visual Studio project files
```

---

## 🔧 How It Works

### 1. **ModelSerializer**
Responsible for converting QObject‑based instances into XML.

Key capabilities:
- Iterates over meta‑properties using `QMetaObject`
- Handles primitives, lists, and nested child objects
- Writes readable, hierarchical XML documents

### 2. **ModelDeserializer**
Reconstructs objects from XML:
- Creates objects through `Instantiator`
- Assigns properties dynamically
- Rebuilds parent relationships (`IParentAdvice` aware)
- Supports dynamic polymorphic types if registered with Qt meta‑type system

### 3. **Custom UTF‑8 Codec**
`CustomUtf8Codec` overrides Qt’s built‑in UTF‑8 behavior for stricter or more permissive XML encoding rules.

---

## 📘 Example Model

Found in `testmodel.*`, this demonstrates:

- Serializing QString, int, lists, enums  
- Nested QObject models  
- Parent relationship handling

---

## 🛠 Usage

### 1. Add project to your `.pro`:
```qmake
include(qt-xml-serialization.pri)
```

### 2. Serialize:
```cpp
ModelSerializer serializer;
serializer.save(rootObject, QFile("output.xml"));
```

### 3. Deserialize:
```cpp
ModelDeserializer deserializer;
QObject* root = deserializer.load(QFile("output.xml"));
```

---

## 🧩 Extending the Framework

You may implement:

- **Custom property visitors**  
- **Additional serializers for specific Qt types**  
- **Plugins for polymorphic type mapping**  
- **Domain‑specific object factories**  

---

## 🧪 Building

### qmake:
```bash
qmake qt-xml-serialization.pro
make
```

### MSVC:
Open `qt-xml-serialization.sln` in Visual Studio.

---

## 📄 License

The project appears to be distributed without explicit license information.  
Please add a LICENSE file if you intend public distribution.

