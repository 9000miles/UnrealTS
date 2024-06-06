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

UsingCppType(SSpinBox);
UsingTSharedPtr(SSpinBox);

namespace $SSpinBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SSpinBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FSpinBoxStyle, Style, FSpinBoxStyle);
		$SLATE_ATTRIBUTE(NumericType, Value, );
		$SLATE_ATTRIBUTE(TOptional< NumericType >, MinValue, );
		$SLATE_ATTRIBUTE(TOptional< NumericType >, MaxValue, );
		$SLATE_ATTRIBUTE(TOptional< NumericType >, MinSliderValue, );
		$SLATE_ATTRIBUTE(TOptional< NumericType >, MaxSliderValue, );
		$SLATE_ATTRIBUTE(TOptional< int32 >, MinFractionalDigits, );
		$SLATE_ATTRIBUTE(TOptional< int32 >, MaxFractionalDigits, );
		$SLATE_ATTRIBUTE(bool, AlwaysUsesDeltaSnap, );
		$SLATE_ATTRIBUTE(bool, EnableSlider, );
		$SLATE_ATTRIBUTE(NumericType, Delta, );
		$SLATE_ATTRIBUTE(int32, ShiftMouseMovePixelPerDelta, );
		$SLATE_ATTRIBUTE(int32, LinearDeltaSensitivity, );
		$SLATE_ATTRIBUTE(bool, SupportDynamicSliderMaxValue, );
		$SLATE_ATTRIBUTE(bool, SupportDynamicSliderMinValue, );
		//$SLATE_EVENT(FOnDynamicSliderMinMaxValueChanged, OnDynamicSliderMaxValueChanged, );
		//$SLATE_EVENT(FOnDynamicSliderMinMaxValueChanged, OnDynamicSliderMinValueChanged, );
		$SLATE_ATTRIBUTE(float, SliderExponent, );
		$SLATE_ATTRIBUTE(NumericType, SliderExponentNeutralValue, );
		$SLATE_ARGUMENT(bool, EnableWheel, );
		$SLATE_ATTRIBUTE(TOptional< NumericType >, WheelStep, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
		$SLATE_ATTRIBUTE(FMargin, ContentPadding, );
		//$SLATE_EVENT(FOnValueChanged, OnValueChanged, );
		//$SLATE_EVENT(FOnValueCommitted, OnValueCommitted, );
		//$SLATE_EVENT(FSimpleDelegate, OnBeginSliderMovement, );
		//$SLATE_EVENT(FOnValueChanged, OnEndSliderMovement, );
		$SLATE_ATTRIBUTE(bool, ClearKeyboardFocusOnCommit, );
		$SLATE_ATTRIBUTE(bool, SelectAllTextOnCommit, );
		$SLATE_ATTRIBUTE(float, MinDesiredWidth, );
		$SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
		$SLATE_ATTRIBUTE(EKeyboardType, KeyboardType, );
		$SLATE_ARGUMENT(TSharedPtr< INumericTypeInterface<NumericType> >, TypeInterface, );
		$SLATE_ARGUMENT(bool, PreventThrottling, );
		//$SLATE_EVENT(FMenuExtensionDelegate, ContextMenuExtender, );
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

		SSpinBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SSpinBox> Widget = MakeTDecl<SSpinBox>("SSpinBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SSpinBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SSpinBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SSpinBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SSpinBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SSpinBox> Widget = MakeShared<SSpinBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SSpinBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SSpinBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SSpinBox");
		Args.Add<FSpinBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<NumericType>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< NumericType >>("MinValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< NumericType >>("MaxValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< NumericType >>("MinSliderValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< NumericType >>("MaxSliderValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< int32 >>("MinFractionalDigits", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< int32 >>("MaxFractionalDigits", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AlwaysUsesDeltaSnap", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("EnableSlider", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<NumericType>("Delta", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<int32>("ShiftMouseMovePixelPerDelta", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<int32>("LinearDeltaSensitivity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SupportDynamicSliderMaxValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SupportDynamicSliderMinValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnDynamicSliderMinMaxValueChanged>("OnDynamicSliderMaxValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDynamicSliderMinMaxValueChanged>("OnDynamicSliderMinValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<float>("SliderExponent", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<NumericType>("SliderExponentNeutralValue", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("EnableWheel", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional< NumericType >>("WheelStep", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnValueCommitted>("OnValueCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnBeginSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnValueChanged>("OnEndSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EKeyboardType>("KeyboardType", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr< INumericTypeInterface<NumericType> >>("TypeInterface", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("PreventThrottling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMenuExtensionDelegate>("ContextMenuExtender", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SSpinBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SSpinBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSpinBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SSpinBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SSpinBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSpinBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SSpinBox()
	{
		GenDTS();
		RegisterTSharedPtr(SSpinBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SSpinBox::$SNew},
			{"SAssignNew", $SSpinBox::$SAssignNew},
			{"MakeShared", $SSpinBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SSpinBox";
		Def.TypeId = puerts::StaticTypeId<SSpinBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SSpinBox _AutoRegister_SSpinBox;