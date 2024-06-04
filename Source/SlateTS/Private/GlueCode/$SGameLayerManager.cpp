#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(IGameLayer);
UsingTSharedPtr(IGameLayer);

namespace $IGameLayer
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, IGameLayer::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_DEFAULT_SLOT(Content);
		$SLATE_ATTRIBUTE(SceneViewport);
	}

	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const uint8 InfoLength = Info.Length();
		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

		IGameLayer::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<IGameLayer> Widget = MakeTDecl<IGameLayer>("IGameLayer", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<IGameLayer>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<IGameLayer>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<IGameLayer>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<IGameLayer>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<IGameLayer> Widget = MakeShared<IGameLayer>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<IGameLayer>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_IGameLayer
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("IGameLayer");
		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<FSceneViewport*>("SceneViewport", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("IGameLayer").Super("TSharedFromThis")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("IGameLayer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<IGameLayer>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<IGameLayer>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("IGameLayer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<IGameLayer>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_IGameLayer()
	{
		GenDTS();
		RegisterTSharedPtr(IGameLayer);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $IGameLayer::$SNew},
			{"SAssignNew", $IGameLayer::$SAssignNew},
			{"MakeShared", $IGameLayer::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "IGameLayer";
		Def.TypeId = puerts::StaticTypeId<IGameLayer>::get();
		Def.SuperTypeId = puerts::StaticTypeId<TSharedFromThis>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_IGameLayer _AutoRegister_IGameLayer;