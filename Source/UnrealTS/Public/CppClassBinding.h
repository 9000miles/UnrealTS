
#pragma once

#include "JsObject.h"
#include "v8.h"


template<typename T>
class ClassHelper
{
public:
	ClassHelper(T* ptr) :Instance(ptr) {}
	template<typename MemFn, typename... Args>
	void Call(MemFn memFn, Args&&... args)
	{
		static_assert(std::is_member_function_pointer<MemFn>::value, "memFn must be a member function pointer");
		(Instance->*memFn)(std::forward<Args>(args)...);
	}
private:
	T* Instance;
};

class MyClass
{
public:
	void SetA(int32 a) {}
	void SetB(float a) {}
	void SetC(bool a) {}
	void SetD(void* a) {}
};

int mymain()
{
	MyClass* mc = new MyClass();
	ClassHelper<MyClass>* cs = new ClassHelper<MyClass>(mc);
	cs->Call(&MyClass::SetA, 32);
	cs->Call(&MyClass::SetB, 56.0f);
	cs->Call(&MyClass::SetC, false);
	cs->Call(&MyClass::SetD, reinterpret_cast<void*>(32));
	return 2;
}

class BaseClass
{
public:
	BaseClass() {}
	~BaseClass() {}

public:
	virtual void Tick(float Detail) {}

private:

};

class ChildClass :public BaseClass
{

public:
	void Tick(float Detail) override
	{
		UE_LOG(LogTemp, Log, TEXT("ChildClass::Tick"));
	}
};


class $ChildClass;
struct ChildClassHelper;


struct ChildClassHelper
{
	ChildClassHelper($ChildClass* Ptr) :ScriptClass(Ptr) {  }
	void Tick(float d);
	$ChildClass* ScriptClass;
};
class $ChildClass :public ChildClass
{
public:
	$ChildClass(const FJsObject& JsObject) : Super(new ChildClassHelper(this)), JsThis(JsObject) {  }
	void __bind__(FJsObject JsObject)
	{
		JsThis = JsObject;
	}
	void Tick(float Detail)
	{
		//ChildClass::Tick(Detail);
		UE_LOG(LogTemp, Log, TEXT("Script_ChildClass::Tick"));

#if 1
		FJsObject Func = JsThis.Get<FJsObject>("Tick");
		Func.Action(&JsThis, Detail);
		return;
#endif

#if 0
		v8::Local<v8::Value> Value;
		if (!JsThis->Has("Tick", Value)) return;

		v8::Local<v8::Function> Function = Value.As<v8::Function>();
		v8::Local<v8::Value> Args[1] = { puerts::converter::Converter<float>::toScript(JsThis->GetContext(), Detail) };
		v8::Local<v8::Value> JS = { puerts::converter::Converter<FJsObject>::toScript(JsThis->GetContext(), *JsThis) };
		Function->CallAsFunction(JsThis->GetContext(), v8::Undefined(JsThis->GetIsolate()), 1, Args);
#endif
		//Function->CallAsFunction(JsThis.GetContext(), JS, 1, Args);
		//Function->Call(JsThis.GetContext(), JS, 1, Args);
		//Function->Call(JsThis.GetContext(), v8::Undefined(JsThis.GetIsolate()), 1, Args);
	}
public:
	ChildClassHelper* Super;

private:
	FJsObject JsThis;
};


void ChildClassHelper::Tick(float d)
{
	ScriptClass->ChildClass::Tick(d);
}

UsingCppType(BaseClass);
UsingCppType(ChildClass);
UsingCppType($ChildClass);
UsingCppType(ChildClassHelper);

struct AutoRegister_ScriptClass
{
	AutoRegister_ScriptClass()
	{
		puerts::DefineClass<BaseClass>()
			.Constructor()
			.Method("Tick", MakeFunction(&BaseClass::Tick))
			.Register();

		puerts::DefineClass<ChildClass>()
			.Constructor()
			.Extends<BaseClass>()
			.Register();

		puerts::DefineClass<$ChildClass>()
			.Constructor<FJsObject>()
			.Extends<ChildClass>()
			//.Method("Tick", MakeFunction(&Script_ChildClass::Tick))
			.Method("__bind__", MakeFunction(&$ChildClass::__bind__))
			.Property("Super", MakeProperty(&$ChildClass::Super))
			.Register();

		puerts::DefineClass<ChildClassHelper>()
			.Method("Tick", MakeFunction(&ChildClassHelper::Tick))
			.Register();
	}
};

AutoRegister_ScriptClass _AutoRegister_ScriptClass__;

