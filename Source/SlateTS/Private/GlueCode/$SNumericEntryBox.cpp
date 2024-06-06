//#pragma once
//
//#include "CoreMinimal.h"
//#include "JsObject.h"
//#include "Binding.hpp"
//#include "DTSDefine.h"
//#include "TypeInfo.hpp"
//#include "UEDataBinding.hpp"
//#include "Helper/WidgetHelper.hpp"
//#include "DTSHelper.h"
//#include "DTSDefine.h"
//#include "PuertsEx.h"
//#include "Widgets/Input/SNumericEntryBox.h"
//
//UsingCppType(SNumericEntryBox);
//UsingTSharedPtr(SNumericEntryBox);
//
//namespace $SNumericEntryBox
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SNumericEntryBox::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		$SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, EditableTextBoxStyle, );
//		$SLATE_STYLE_ARGUMENT(FSpinBoxStyle, SpinBoxStyle, );
//		$SLATE_NAMED_SLOT(FArguments, Label, );
//		$SLATE_ARGUMENT(EVerticalAlignment, LabelVAlign, );
//		$SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
//		$SLATE_ARGUMENT(ELabelLocation, LabelLocation, );
//		$SLATE_ARGUMENT(FMargin, LabelPadding, );
//		$SLATE_ARGUMENT(FSlateColor, BorderForegroundColor, );
//		$SLATE_ARGUMENT(FSlateColor, BorderBackgroundColor, );
//		$SLATE_ATTRIBUTE(TOptional<NumericType>, Value, );
//		$SLATE_ARGUMENT(FText, UndeterminedString, );
//		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
//		$SLATE_ARGUMENT(bool, AllowSpin, );
//		$SLATE_ARGUMENT(int32, ShiftMouseMovePixelPerDelta, );
//		$SLATE_ATTRIBUTE(int32, LinearDeltaSensitivity, );
//		$SLATE_ATTRIBUTE(bool, SupportDynamicSliderMaxValue, );
//		$SLATE_ATTRIBUTE(bool, SupportDynamicSliderMinValue, );
//		//$SLATE_EVENT(FOnDynamicSliderMinMaxValueChanged, OnDynamicSliderMaxValueChanged, );
//		//$SLATE_EVENT(FOnDynamicSliderMinMaxValueChanged, OnDynamicSliderMinValueChanged, );
//		$SLATE_ATTRIBUTE(NumericType, Delta, );
//		$SLATE_ATTRIBUTE(TOptional< NumericType >, MinValue, );
//		$SLATE_ATTRIBUTE(TOptional< NumericType >, MaxValue, );
//		$SLATE_ATTRIBUTE(TOptional< NumericType >, MinSliderValue, );
//		$SLATE_ATTRIBUTE(TOptional< NumericType >, MaxSliderValue, );
//		$SLATE_ATTRIBUTE(float, SliderExponent, );
//		$SLATE_ATTRIBUTE(NumericType, SliderExponentNeutralValue, );
//		$SLATE_ARGUMENT(bool, AllowWheel, );
//		$SLATE_ATTRIBUTE(TOptional< NumericType >, WheelStep, );
//		$SLATE_ATTRIBUTE(float, MinDesiredValueWidth, );
//		$SLATE_ATTRIBUTE(FMargin, OverrideTextMargin, );
//		//$SLATE_EVENT(FOnValueChanged, OnValueChanged, );
//		//$SLATE_EVENT(FOnValueCommitted, OnValueCommitted, );
//		//$SLATE_EVENT(FOnUndeterminedValueChanged, OnUndeterminedValueChanged, );
//		//$SLATE_EVENT(FOnUndeterminedValueCommitted, OnUndeterminedValueCommitted, );
//		//$SLATE_EVENT(FSimpleDelegate, OnBeginSliderMovement, );
//		//$SLATE_EVENT(FOnValueChanged, OnEndSliderMovement, );
//		//$SLATE_EVENT(FMenuExtensionDelegate, ContextMenuExtender, );
//		$SLATE_ARGUMENT(TSharedPtr< INumericTypeInterface<NumericType> >, TypeInterface, );
//		$SLATE_ARGUMENT(bool, DisplayToggle, );
//		$SLATE_ATTRIBUTE(ECheckBoxState, ToggleChecked, );
//		//$SLATE_EVENT(FOnCheckStateChanged, OnToggleChanged, );
//		$SLATE_ARGUMENT(FMargin, TogglePadding, );
//	}
//
//	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//		const uint8 InfoLength = Info.Length();
//		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }
//
//		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
//		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
//		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;
//
//		SNumericEntryBox::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SNumericEntryBox> Widget = MakeTDecl<SNumericEntryBox>("SNumericEntryBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericEntryBox>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SNumericEntryBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SNumericEntryBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SNumericEntryBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SNumericEntryBox> Widget = MakeShared<SNumericEntryBox>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericEntryBox>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SNumericEntryBox
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SNumericEntryBox");
//		Args.Add<FEditableTextBoxStyle>("EditableTextBoxStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
//		Args.Add<FSpinBoxStyle>("SpinBoxStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
//		Args.Add<FArguments>("Label", DTS::EArgType::SLATE_NAMED_SLOT);
//		Args.Add<EVerticalAlignment>("LabelVAlign", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<ELabelLocation>("LabelLocation", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FMargin>("LabelPadding", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FSlateColor>("BorderForegroundColor", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FSlateColor>("BorderBackgroundColor", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<TOptional<NumericType>>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FText>("UndeterminedString", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("AllowSpin", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<int32>("ShiftMouseMovePixelPerDelta", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<int32>("LinearDeltaSensitivity", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("SupportDynamicSliderMaxValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("SupportDynamicSliderMinValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FOnDynamicSliderMinMaxValueChanged>("OnDynamicSliderMaxValueChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnDynamicSliderMinMaxValueChanged>("OnDynamicSliderMinValueChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<NumericType>("Delta", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional< NumericType >>("MinValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional< NumericType >>("MaxValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional< NumericType >>("MinSliderValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional< NumericType >>("MaxSliderValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<float>("SliderExponent", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<NumericType>("SliderExponentNeutralValue", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("AllowWheel", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<TOptional< NumericType >>("WheelStep", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<float>("MinDesiredValueWidth", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FMargin>("OverrideTextMargin", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnValueCommitted>("OnValueCommitted", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnUndeterminedValueChanged>("OnUndeterminedValueChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnUndeterminedValueCommitted>("OnUndeterminedValueCommitted", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FSimpleDelegate>("OnBeginSliderMovement", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnValueChanged>("OnEndSliderMovement", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FMenuExtensionDelegate>("ContextMenuExtender", DTS::EArgType::SLATE_EVENT);
//		Args.Add<TSharedPtr< INumericTypeInterface<NumericType> >>("TypeInterface", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<bool>("DisplayToggle", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<ECheckBoxState>("ToggleChecked", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FOnCheckStateChanged>("OnToggleChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FMargin>("TogglePadding", DTS::EArgType::SLATE_ARGUMENT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SNumericEntryBox").Super("SCompoundWidget")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SNumericEntryBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericEntryBox>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SNumericEntryBox>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SNumericEntryBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericEntryBox>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SNumericEntryBox()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SNumericEntryBox);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SNumericEntryBox::$SNew},
//			{"SAssignNew", $SNumericEntryBox::$SAssignNew},
//			{"MakeShared", $SNumericEntryBox::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SNumericEntryBox";
//		Def.TypeId = puerts::StaticTypeId<SNumericEntryBox>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SNumericEntryBox _AutoRegister_SNumericEntryBox;