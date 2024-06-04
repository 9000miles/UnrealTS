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

UsingCppType(SNumericDropDown);
UsingTSharedPtr(SNumericDropDown);

namespace $SNumericDropDown
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SNumericDropDown::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(DropDownValues);
		$SLATE_ATTRIBUTE(LabelText);
		$SLATE_ATTRIBUTE(Orientation);
		$SLATE_ATTRIBUTE(MinDesiredValueWidth);
		$SLATE_ATTRIBUTE(bShowNamedValue);
		$SLATE_ATTRIBUTE(Value);
		$SLATE_EVENT(OnValueChanged);
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

		SNumericDropDown::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SNumericDropDown> Widget = MakeTDecl<SNumericDropDown>("SNumericDropDown", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericDropDown>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SNumericDropDown>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SNumericDropDown>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SNumericDropDown>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SNumericDropDown> Widget = MakeShared<SNumericDropDown>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericDropDown>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SNumericDropDown
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SNumericDropDown");
		Args.Add<TArray<FNamedValue>>("DropDownValues", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("LabelText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EOrientation>("Orientation", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredValueWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("bShowNamedValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<NumericType>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SNumericDropDown").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SNumericDropDown.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericDropDown>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SNumericDropDown>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SNumericDropDown.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericDropDown>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SNumericDropDown()
	{
		GenDTS();
		RegisterTSharedPtr(SNumericDropDown);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SNumericDropDown::$SNew},
			{"SAssignNew", $SNumericDropDown::$SAssignNew},
			{"MakeShared", $SNumericDropDown::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SNumericDropDown";
		Def.TypeId = puerts::StaticTypeId<SNumericDropDown>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SNumericDropDown _AutoRegister_SNumericDropDown;