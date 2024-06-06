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
#include "AdvancedWidgets/Public/Widgets/SRadialSlider.h"

UsingCppType(SRadialSlider);
UsingTSharedPtr(SRadialSlider);

namespace $SRadialSlider
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SRadialSlider::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(bool, MouseUsesStep, );
		$SLATE_ARGUMENT(bool, RequiresControllerLock, );
		$SLATE_ATTRIBUTE(bool, Locked, );
		$SLATE_ATTRIBUTE(FSlateColor, SliderBarColor, );
		$SLATE_ATTRIBUTE(FSlateColor, SliderProgressColor, );
		$SLATE_ATTRIBUTE(FSlateColor, SliderHandleColor, );
		$SLATE_ATTRIBUTE(FSlateColor, CenterBackgroundColor, );
		$SLATE_ATTRIBUTE(float, Thickness, float);
		$SLATE_ARGUMENT(FSlateBrush, CenterBackgroundBrush, );
		$SLATE_STYLE_ARGUMENT(FSliderStyle, Style, FSliderStyle);
		$SLATE_ATTRIBUTE(float, StepSize, );
		$SLATE_ATTRIBUTE(float, Value, float);
		$SLATE_ATTRIBUTE(bool, bUseCustomDefaultValue, );
		$SLATE_ATTRIBUTE(float, CustomDefaultValue, );
		$SLATE_ARGUMENT(FRuntimeFloatCurve, SliderRange, );
		$SLATE_ARGUMENT(float, SliderHandleStartAngle, );
		$SLATE_ARGUMENT(float, SliderHandleEndAngle, );
		$SLATE_ARGUMENT(float, AngularOffset, );
		$SLATE_ARGUMENT(FVector2D, HandStartEndRatio, );
		$SLATE_ARGUMENT(TArray<float>, ValueTags, );
		$SLATE_ARGUMENT(bool, IsFocusable, );
		$SLATE_ARGUMENT(bool, UseVerticalDrag, );
		$SLATE_ARGUMENT(bool, ShowSliderHandle, );
		$SLATE_ARGUMENT(bool, ShowSliderHand, );
		//$SLATE_EVENT(FSimpleDelegate, OnMouseCaptureBegin, );
		//$SLATE_EVENT(FSimpleDelegate, OnMouseCaptureEnd, );
		//$SLATE_EVENT(FSimpleDelegate, OnControllerCaptureBegin, );
		//$SLATE_EVENT(FSimpleDelegate, OnControllerCaptureEnd, );
		//$SLATE_EVENT(FOnFloatValueChanged, OnValueChanged, );
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

		SRadialSlider::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SRadialSlider> Widget = MakeTDecl<SRadialSlider>("SRadialSlider", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SRadialSlider>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SRadialSlider>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SRadialSlider>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SRadialSlider>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SRadialSlider> Widget = MakeShared<SRadialSlider>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SRadialSlider>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SRadialSlider
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SRadialSlider");
		Args.Add<bool>("MouseUsesStep", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("RequiresControllerLock", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("Locked", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("SliderBarColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("SliderProgressColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("SliderHandleColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("CenterBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("Thickness", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateBrush>("CenterBackgroundBrush", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSliderStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<float>("StepSize", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("bUseCustomDefaultValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("CustomDefaultValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FRuntimeFloatCurve>("SliderRange", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("SliderHandleStartAngle", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("SliderHandleEndAngle", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("AngularOffset", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("HandStartEndRatio", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TArray<float>>("ValueTags", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("UseVerticalDrag", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowSliderHandle", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowSliderHand", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSimpleDelegate>("OnMouseCaptureBegin", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnMouseCaptureEnd", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnControllerCaptureBegin", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnControllerCaptureEnd", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnFloatValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SRadialSlider").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SRadialSlider.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SRadialSlider>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SRadialSlider>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SRadialSlider.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SRadialSlider>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SRadialSlider()
	{
		GenDTS();
		RegisterTSharedPtr(SRadialSlider);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SRadialSlider::$SNew},
			{"SAssignNew", $SRadialSlider::$SAssignNew},
			{"MakeShared", $SRadialSlider::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SRadialSlider";
		Def.TypeId = puerts::StaticTypeId<SRadialSlider>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SRadialSlider _AutoRegister_SRadialSlider;