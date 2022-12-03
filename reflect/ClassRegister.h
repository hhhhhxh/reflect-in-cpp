#ifndef _CLASSREGISTER_H_
#define _CLASSREGISTER_H_

#include "ClassFactory.h"

namespace reflect {
class ClassRegister {
public:
    // register class
    ClassRegister(const string &className, create_object method) {
        Singleton<ClassFactory>::instance()->register_class(className, method);
    }

    // register class field
    ClassRegister(const string &className, const string &fieldName, const string &fieldType, uintptr_t offset) {
        Singleton<ClassFactory>::instance()->register_class_field(className, fieldName, fieldType, offset);
    }

    // register class method
    ClassRegister(const string &className, const string &methodName, uintptr_t method) {
        Singleton<ClassFactory>::instance()->register_class_method(className, methodName, method);
    }
};

#define REGISTER_CLASS(className)        \
    Object *createObject##className() {  \
        Object *obj = new className();   \
        obj->set_class_name(#className); \
        return obj;                      \
    }                                    \
    ClassRegister classRegister##classname(#className, createObject##className)

#define REGISTER_CLASS_FIELD(className, fieldName, fieldType) \
    className className##fieldName;                           \
    ClassRegister classRegister##className##fieldName(#className, #fieldName, #fieldType, (size_t)(&(className##fieldName.fieldName)) - (size_t)(&className##fieldName))

#define REGISTER_CLASS_METHOD(className, methodName, returnType, ...)                                             \
    std::function<returnType(className *, ##__VA_ARGS__)> className##methodName##method = &className::methodName; \
    ClassRegister classRegister##className##methodName(#className, #methodName, (uintptr_t) & (className##methodName##method))

} // namespace reflect

#endif // _CLASSREGISTER_H_