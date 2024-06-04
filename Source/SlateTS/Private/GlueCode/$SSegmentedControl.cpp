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

UsingCppType(SSegmentedControl);
UsingTSharedPtr(SSegmentedControl);

namespace $SSegmentedControl
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SSegmentedControl::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_SLOT_ARGUMENT(Slots);
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_STYLE_ARGUMENT(TextStyle);
		$SLATE_ARGUMENT(SupportsMultiSelection);
		$SLATE_ARGUMENT(SupportsEmptySelection);
		$SLATE_ATTRIBUTE(Value);
		$SLATE_ATTRIBUTE(Values);
		$SLATE_ATTRIBUTE(UniformPadding);
		$SLATE_EVENT(OnValueChanged);
		$SLATE_EVENT(OnValuesChanged);
		$SLATE_EVENT(OnValueChecked);
		$SLATE_ARGUMENT(MaxSegmentsPerLine);
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

		SSegmentedControl::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SSegmentedControl> Widget = MakeTDecl<SSegmentedControl>("SSegmentedControl", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SSegmentedControl>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SSegmentedControl>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SSegmentedControl>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SSegmentedControl>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SSegmentedControl> Widget = MakeShared<SSegmentedControl>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SSegmentedControl>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SSegmentedControl
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SSegmentedControl");
		Args.Add<FSlot>("Slots", DTS::EArgType::SLATE_SLOT_ARGUMENT);
		Args.Add<FSegmentedControlStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<bool>("SupportsMultiSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsEmptySelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<OptionType>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TArray<OptionType>>("Values", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("UniformPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnValuesChanged>("OnValuesChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnValueChecked>("OnValueChecked", DTS::EArgType::SLATE_EVENT);
		Args.Add<int32>("MaxSegmentsPerLine", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SSegmentedControl").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SSegmentedControl.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSegmentedControl>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SSegmentedControl>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SSegmentedControl.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSegmentedControl>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SSegmentedControl()
	{
		GenDTS();
		RegisterTSharedPtr(SSegmentedControl);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SSegmentedControl::$SNew},
			{"SAssignNew", $SSegmentedControl::$SAssignNew},
			{"MakeShared", $SSegmentedControl::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SSegmentedControl";
		Def.TypeId = puerts::StaticTypeId<SSegmentedControl>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SSegmentedControl _AutoRegister_SSegmentedControl;