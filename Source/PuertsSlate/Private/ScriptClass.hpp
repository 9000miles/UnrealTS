#include "JsObject.h"
#include "v8.h"


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


class Script_ChildClass;
struct FChildClass_Proxy;


struct FChildClass_Proxy
{
	FChildClass_Proxy(Script_ChildClass* Ptr) :ScriptClass(Ptr) {  }
	void Tick(float d);
	Script_ChildClass* ScriptClass;
};
class Script_ChildClass :public ChildClass
{
public:
	Script_ChildClass(const FJsObject& JsObject)
		:JsThis(JsObject),
		Super(new FChildClass_Proxy(this))
	{

	}

	void Register(FJsObject JsObject)
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

		v8::Local<v8::Value> Value;
		if (!JsThis.Has("Tick", Value)) return;

		v8::Local<v8::Function> Function = Value.As<v8::Function>();
		v8::Local<v8::Value> Args[1] = { puerts::converter::Converter<float>::toScript(JsThis.GetContext(), Detail) };
		v8::Local<v8::Value> JS = { puerts::converter::Converter<FJsObject>::toScript(JsThis.GetContext(), JsThis) };
		Function->CallAsFunction(JsThis.GetContext(), v8::Undefined(JsThis.GetIsolate()), 1, Args);
		//Function->CallAsFunction(JsThis.GetContext(), JS, 1, Args);
		//Function->Call(JsThis.GetContext(), JS, 1, Args);
		//Function->Call(JsThis.GetContext(), v8::Undefined(JsThis.GetIsolate()), 1, Args);
	}
public:
	FChildClass_Proxy* Super;

private:
	FJsObject JsThis;
};


void FChildClass_Proxy::Tick(float d)
{
	ScriptClass->ChildClass::Tick(d);
}

UsingCppType(BaseClass);
UsingCppType(ChildClass);
UsingCppType(Script_ChildClass);
UsingCppType(FChildClass_Proxy);

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

		puerts::DefineClass<Script_ChildClass>()
			.Constructor<FJsObject>()
			.Extends<ChildClass>()
			//.Method("Tick", MakeFunction(&Script_ChildClass::Tick))
			.Method("Register", MakeFunction(&Script_ChildClass::Register))
			.Property("Super", MakeProperty(&Script_ChildClass::Super))
			.Register();

		puerts::DefineClass<FChildClass_Proxy>()
			.Method("Tick", MakeFunction(&FChildClass_Proxy::Tick))
			.Register();
	}
};

AutoRegister_ScriptClass _AutoRegister_ScriptClass__;

