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
#include "Widgets/Colors/SColorGradingWheel.h"

UsingCppType(SColorGradingWheel);
UsingTSharedPtr(SColorGradingWheel);

namespace $SColorGradingWheel
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SColorGradingWheel::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FLinearColor, SelectedColor, );
		$SLATE_ATTRIBUTE(int32, DesiredWheelSize, );
		$SLATE_ATTRIBUTE(float, ExponentDisplacement, );
		//$SLATE_EVENT(FOnColorGradingWheelMouseCapture, OnMouseCaptureBegin, );
		//$SLATE_EVENT(FOnColorGradingWheelMouseCapture, OnMouseCaptureEnd, );
		//$SLATE_EVENT(FOnColorGradingWheelValueChanged, OnValueChanged, );
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

		SColorGradingWheel::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SColorGradingWheel> Widget = MakeTDecl<SColorGradingWheel>("SColorGradingWheel", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SColorGradingWheel>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SColorGradingWheel>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SColorGradingWheel>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SColorGradingWheel>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SColorGradingWheel> Widget = MakeShared<SColorGradingWheel>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SColorGradingWheel>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SColorGradingWheel
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SColorGradingWheel");
		Args.Add<FLinearColor>("SelectedColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<int32>("DesiredWheelSize", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("ExponentDisplacement", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<SColorGradingWheel::FOnColorGradingWheelMouseCapture>("OnMouseCaptureBegin", DTS::EArgType::SLATE_EVENT);
		Args.Add<SColorGradingWheel::FOnColorGradingWheelMouseCapture>("OnMouseCaptureEnd", DTS::EArgType::SLATE_EVENT);
		Args.Add<SColorGradingWheel::FOnColorGradingWheelValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SColorGradingWheel").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SColorGradingWheel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingWheel>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingWheel>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SColorGradingWheel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingWheel>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SColorGradingWheel()
	{
		GenDTS();
		RegisterTSharedPtr(SColorGradingWheel);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SColorGradingWheel::$SNew},
			{"SAssignNew", $SColorGradingWheel::$SAssignNew},
			{"MakeShared", $SColorGradingWheel::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SColorGradingWheel";
		Def.TypeId = puerts::StaticTypeId<SColorGradingWheel>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SColorGradingWheel _AutoRegister_SColorGradingWheel;