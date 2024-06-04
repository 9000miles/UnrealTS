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
#include "AppFramework/Public/Widgets/Colors/SColorGradingPicker.h"

UsingCppType(SColorGradingPicker);
UsingTSharedPtr(SColorGradingPicker);

namespace $SColorGradingPicker
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SColorGradingPicker::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(ValueMin);
		$SLATE_ARGUMENT(ValueMax);
		$SLATE_ARGUMENT(SliderValueMin);
		$SLATE_ARGUMENT(SliderValueMax);
		$SLATE_ATTRIBUTE(AllowSpin);
		$SLATE_ATTRIBUTE(SupportDynamicSliderMaxValue);
		$SLATE_ATTRIBUTE(SupportDynamicSliderMinValue);
		$SLATE_ARGUMENT(MainDelta);
		$SLATE_ARGUMENT(MainShiftMouseMovePixelPerDelta);
		$SLATE_ARGUMENT(ColorGradingModes);
		$SLATE_EVENT(OnColorCommitted);
		$SLATE_EVENT(OnQueryCurrentColor);
		$SLATE_EVENT(OnBeginSliderMovement);
		$SLATE_EVENT(OnEndSliderMovement);
		$SLATE_EVENT(OnBeginMouseCapture);
		$SLATE_EVENT(OnEndMouseCapture);
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

		SColorGradingPicker::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SColorGradingPicker> Widget = MakeTDecl<SColorGradingPicker>("SColorGradingPicker", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SColorGradingPicker>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SColorGradingPicker>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SColorGradingPicker>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SColorGradingPicker>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SColorGradingPicker> Widget = MakeShared<SColorGradingPicker>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SColorGradingPicker>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SColorGradingPicker
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SColorGradingPicker");
		Args.Add<TOptional<float>>("ValueMin", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("ValueMax", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("SliderValueMin", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("SliderValueMax", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AllowSpin", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SupportDynamicSliderMaxValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SupportDynamicSliderMinValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MainDelta", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<int32>("MainShiftMouseMovePixelPerDelta", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EColorGradingModes>("ColorGradingModes", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnColorGradingPickerValueChanged>("OnColorCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGetCurrentVector4Value>("OnQueryCurrentColor", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnBeginSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnEndSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnBeginMouseCapture", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnEndMouseCapture", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SColorGradingPicker").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SColorGradingPicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingPicker>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingPicker>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SColorGradingPicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorGradingPicker>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SColorGradingPicker()
	{
		GenDTS();
		RegisterTSharedPtr(SColorGradingPicker);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SColorGradingPicker::$SNew},
			{"SAssignNew", $SColorGradingPicker::$SAssignNew},
			{"MakeShared", $SColorGradingPicker::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SColorGradingPicker";
		Def.TypeId = puerts::StaticTypeId<SColorGradingPicker>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SColorGradingPicker _AutoRegister_SColorGradingPicker;