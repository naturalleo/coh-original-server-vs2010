/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSHTMLOptionsCollection.h"

#include "HTMLOptionsCollection.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLOptionsCollection);

/* Hash table */

static const HashTableValue JSHTMLOptionsCollectionTableValues[4] =
{
    { "selectedIndex", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionSelectedIndex), (intptr_t)setJSHTMLOptionsCollectionSelectedIndex },
    { "length", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionLength), (intptr_t)setJSHTMLOptionsCollectionLength },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSHTMLOptionsCollectionTableValues, 0 };
#else
    { 9, 7, JSHTMLOptionsCollectionTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLOptionsCollectionConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLOptionsCollectionConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLOptionsCollectionConstructorTableValues, 0 };
#endif

class JSHTMLOptionsCollectionConstructor : public DOMConstructorObject {
public:
    JSHTMLOptionsCollectionConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLOptionsCollectionConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLOptionsCollectionPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLOptionsCollectionConstructor::s_info = { "HTMLOptionsCollectionConstructor", 0, &JSHTMLOptionsCollectionConstructorTable, 0 };

bool JSHTMLOptionsCollectionConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionsCollectionConstructor, DOMObject>(exec, &JSHTMLOptionsCollectionConstructorTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollectionConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionsCollectionConstructor, DOMObject>(exec, &JSHTMLOptionsCollectionConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLOptionsCollectionPrototypeTableValues[3] =
{
    { "add", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsHTMLOptionsCollectionPrototypeFunctionAdd), (intptr_t)2 },
    { "remove", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsHTMLOptionsCollectionPrototypeFunctionRemove), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSHTMLOptionsCollectionPrototypeTableValues, 0 };
#else
    { 4, 3, JSHTMLOptionsCollectionPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLOptionsCollectionPrototype::s_info = { "HTMLOptionsCollectionPrototype", 0, &JSHTMLOptionsCollectionPrototypeTable, 0 };

JSObject* JSHTMLOptionsCollectionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLOptionsCollection>(exec, globalObject);
}

bool JSHTMLOptionsCollectionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLOptionsCollectionPrototypeTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollectionPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLOptionsCollectionPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLOptionsCollection::s_info = { "HTMLOptionsCollection", &JSHTMLCollection::s_info, &JSHTMLOptionsCollectionTable, 0 };

JSHTMLOptionsCollection::JSHTMLOptionsCollection(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLOptionsCollection> impl)
    : JSHTMLCollection(structure, globalObject, impl)
{
}

JSObject* JSHTMLOptionsCollection::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLOptionsCollectionPrototype(JSHTMLOptionsCollectionPrototype::createStructure(JSHTMLCollectionPrototype::self(exec, globalObject)));
}

bool JSHTMLOptionsCollection::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionsCollection, Base>(exec, &JSHTMLOptionsCollectionTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollection::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionsCollection, Base>(exec, &JSHTMLOptionsCollectionTable, this, propertyName, descriptor);
}

JSValue jsHTMLOptionsCollectionSelectedIndex(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionsCollection* imp = static_cast<HTMLOptionsCollection*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->selectedIndex());
    return result;
}

JSValue jsHTMLOptionsCollectionLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    return castedThis->length(exec);
}

JSValue jsHTMLOptionsCollectionConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* domObject = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    return JSHTMLOptionsCollection::getConstructor(exec, domObject->globalObject());
}
void JSHTMLOptionsCollection::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok) {
        indexSetter(exec, index, value);
        return;
    }
    lookupPut<JSHTMLOptionsCollection, Base>(exec, propertyName, value, &JSHTMLOptionsCollectionTable, this, slot);
}

void JSHTMLOptionsCollection::put(ExecState* exec, unsigned propertyName, JSValue value)
{
    indexSetter(exec, propertyName, value);
    return;
}

void setJSHTMLOptionsCollectionSelectedIndex(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionsCollection* castedThisObj = static_cast<JSHTMLOptionsCollection*>(thisObject);
    HTMLOptionsCollection* imp = static_cast<HTMLOptionsCollection*>(castedThisObj->impl());
    imp->setSelectedIndex(value.toInt32(exec));
}

void setJSHTMLOptionsCollectionLength(ExecState* exec, JSObject* thisObject, JSValue value)
{
    static_cast<JSHTMLOptionsCollection*>(thisObject)->setLength(exec, value);
}

JSValue JSHTMLOptionsCollection::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLOptionsCollectionConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsHTMLOptionsCollectionPrototypeFunctionAdd(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLOptionsCollection::s_info))
        return throwError(exec, TypeError);
    JSHTMLOptionsCollection* castedThisObj = static_cast<JSHTMLOptionsCollection*>(asObject(thisValue));
    return castedThisObj->add(exec, args);
}

JSValue JSC_HOST_CALL jsHTMLOptionsCollectionPrototypeFunctionRemove(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLOptionsCollection::s_info))
        return throwError(exec, TypeError);
    JSHTMLOptionsCollection* castedThisObj = static_cast<JSHTMLOptionsCollection*>(asObject(thisValue));
    return castedThisObj->remove(exec, args);
}

HTMLOptionsCollection* toHTMLOptionsCollection(JSC::JSValue value)
{
    return value.inherits(&JSHTMLOptionsCollection::s_info) ? static_cast<JSHTMLOptionsCollection*>(asObject(value))->impl() : 0;
}

}
