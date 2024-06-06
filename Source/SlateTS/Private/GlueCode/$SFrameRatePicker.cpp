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
#include "TimeManagement/Public/Widgets/SFrameRatePicker.h"

UsingCppType(SFrameRatePicker);
UsingTSharedPtr(SFrameRatePicker);

namespace $SFrameRatePicker
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SFrameRatePicker::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FComboButtonStyle, ComboButtonStyle, );
		$SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
		$SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
		$SLATE_ATTRIBUTE(FMargin, ContentPadding, );
		$SLATE_ATTRIBUTE(FFrameRate, Value, FFrameRate);
		//$SLATE_EVENT(FOnValueChanged, OnValueChanged, );
		$SLATE_ATTRIBUTE(bool, HasMultipleValues, );
		$SLATE_ARGUMENT(TArray<FCommonFrameRateInfo>, PresetValues, );
		$SLATE_ATTRIBUTE(FText, RecommendedText, );
		$SLATE_ATTRIBUTE(FText, NotRecommendedText, );
		$SLATE_ATTRIBUTE(FText, NotRecommendedToolTip, );
		//$SLATE_EVENT(FIsPresetRecommended, IsPresetRecommended, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
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

		SFrameRatePicker::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SFrameRatePicker> Widget = MakeTDecl<SFrameRatePicker>("SFrameRatePicker", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SFrameRatePicker>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SFrameRatePicker>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SFrameRatePicker>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SFrameRatePicker>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SFrameRatePicker> Widget = MakeShared<SFrameRatePicker>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SFrameRatePicker>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SFrameRatePicker
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SFrameRatePicker");
		Args.Add<FComboButtonStyle>("ComboButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FFrameRate>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<SFrameRatePicker::FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("HasMultipleValues", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TArray<FCommonFrameRateInfo>>("PresetValues", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("RecommendedText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("NotRecommendedText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("NotRecommendedToolTip", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<SFrameRatePicker::FIsPresetRecommended>("IsPresetRecommended", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SFrameRatePicker").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SFrameRatePicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SFrameRatePicker>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SFrameRatePicker>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SFrameRatePicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SFrameRatePicker>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SFrameRatePicker()
	{
		GenDTS();
		RegisterTSharedPtr(SFrameRatePicker);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SFrameRatePicker::$SNew},
			{"SAssignNew", $SFrameRatePicker::$SAssignNew},
			{"MakeShared", $SFrameRatePicker::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SFrameRatePicker";
		Def.TypeId = puerts::StaticTypeId<SFrameRatePicker>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SFrameRatePicker _AutoRegister_SFrameRatePicker;