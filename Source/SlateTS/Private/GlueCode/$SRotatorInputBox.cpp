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
//#include "Widgets/Input/SRotatorInputBox.h"
//
//UsingCppType(SNumericRotatorInputBox);
//UsingTSharedPtr(SNumericRotatorInputBox);
//
//namespace $SNumericRotatorInputBox
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SNumericRotatorInputBox::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		$SLATE_ATTRIBUTE(TOptional<NumericType>, Roll, );
//		$SLATE_ATTRIBUTE(TOptional<NumericType>, Pitch, );
//		$SLATE_ATTRIBUTE(TOptional<NumericType>, Yaw, );
//		$SLATE_ARGUMENT(bool, bColorAxisLabels, );
//		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
//		$SLATE_ARGUMENT(bool, AllowSpin, );
//		//$SLATE_EVENT(FOnNumericValueChanged, OnPitchChanged, );
//		//$SLATE_EVENT(FOnNumericValueChanged, OnYawChanged, );
//		//$SLATE_EVENT(FOnNumericValueChanged, OnRollChanged, );
//		//$SLATE_EVENT(FOnNumericValueCommitted, OnPitchCommitted, );
//		//$SLATE_EVENT(FOnNumericValueCommitted, OnYawCommitted, );
//		//$SLATE_EVENT(FOnNumericValueCommitted, OnRollCommitted, );
//		//$SLATE_EVENT(FSimpleDelegate, OnBeginSliderMovement, );
//		//$SLATE_EVENT(FOnNumericValueChanged, OnEndSliderMovement, );
//		$SLATE_ARGUMENT(TSharedPtr< INumericTypeInterface<NumericType> >, TypeInterface, );
//		$SLATE_ARGUMENT(bool, DisplayToggle, );
//		$SLATE_ATTRIBUTE(ECheckBoxState, TogglePitchChecked, );
//		$SLATE_ATTRIBUTE(ECheckBoxState, ToggleYawChecked, );
//		$SLATE_ATTRIBUTE(ECheckBoxState, ToggleRollChecked, );
//		//$SLATE_EVENT(FOnCheckStateChanged, OnTogglePitchChanged, );
//		//$SLATE_EVENT(FOnCheckStateChanged, OnToggleYawChanged, );
//		//$SLATE_EVENT(FOnCheckStateChanged, OnToggleRollChanged, );
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
//		SNumericRotatorInputBox::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SNumericRotatorInputBox> Widget = MakeTDecl<SNumericRotatorInputBox>("SNumericRotatorInputBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericRotatorInputBox>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SNumericRotatorInputBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SNumericRotatorInputBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SNumericRotatorInputBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SNumericRotatorInputBox> Widget = MakeShared<SNumericRotatorInputBox>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericRotatorInputBox>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SNumericRotatorInputBox
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SNumericRotatorInputBox");
//		Args.Add<TOptional<NumericType>>("Roll", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional<NumericType>>("Pitch", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<TOptional<NumericType>>("Yaw", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("bColorAxisLabels", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("AllowSpin", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FOnNumericValueChanged>("OnPitchChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueChanged>("OnYawChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueChanged>("OnRollChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueCommitted>("OnPitchCommitted", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueCommitted>("OnYawCommitted", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueCommitted>("OnRollCommitted", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FSimpleDelegate>("OnBeginSliderMovement", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnNumericValueChanged>("OnEndSliderMovement", DTS::EArgType::SLATE_EVENT);
//		Args.Add<TSharedPtr< INumericTypeInterface<NumericType> >>("TypeInterface", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<bool>("DisplayToggle", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<ECheckBoxState>("TogglePitchChecked", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<ECheckBoxState>("ToggleYawChecked", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<ECheckBoxState>("ToggleRollChecked", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FOnCheckStateChanged>("OnTogglePitchChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnCheckStateChanged>("OnToggleYawChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnCheckStateChanged>("OnToggleRollChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FMargin>("TogglePadding", DTS::EArgType::SLATE_ARGUMENT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SNumericRotatorInputBox").Super("SCompoundWidget")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SNumericRotatorInputBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericRotatorInputBox>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SNumericRotatorInputBox>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SNumericRotatorInputBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericRotatorInputBox>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SNumericRotatorInputBox()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SNumericRotatorInputBox);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SNumericRotatorInputBox::$SNew},
//			{"SAssignNew", $SNumericRotatorInputBox::$SAssignNew},
//			{"MakeShared", $SNumericRotatorInputBox::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SNumericRotatorInputBox";
//		Def.TypeId = puerts::StaticTypeId<SNumericRotatorInputBox>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SNumericRotatorInputBox _AutoRegister_SNumericRotatorInputBox;