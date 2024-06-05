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

UsingCppType(SNumericVectorInputBox);
UsingTSharedPtr(SNumericVectorInputBox);

namespace $SNumericVectorInputBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SNumericVectorInputBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(TOptional<VectorType>, Vector, );
		$SLATE_ATTRIBUTE(TOptional<VectorType>, MinVector, );
		$SLATE_ATTRIBUTE(TOptional<VectorType>, MaxVector, );
		$SLATE_ATTRIBUTE(TOptional<VectorType>, MinSliderVector, );
		$SLATE_ATTRIBUTE(TOptional<VectorType>, MaxSliderVector, );
		$SLATE_EVENT(FOnVectorValueChanged, OnVectorChanged, );
		$SLATE_EVENT(FOnVectorValueCommitted, OnVectorCommitted, );
		$SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, EditableTextBoxStyle, );
		$SLATE_STYLE_ARGUMENT(FSpinBoxStyle, SpinBoxStyle, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
		$SLATE_ARGUMENT(bool, AllowSpin, );
		$SLATE_ATTRIBUTE(NumericType, SpinDelta, );
		$SLATE_ARGUMENT(bool, bColorAxisLabels, );
		$SLATE_EVENT(FSimpleDelegate, OnBeginSliderMovement, );
		$SLATE_EVENT(FOnNumericValueChanged, OnEndSliderMovement, );
		$SLATE_ARGUMENT(TSharedPtr< INumericTypeInterface<NumericType> >, TypeInterface, );
		$SLATE_ARGUMENT(bool, DisplayToggle, );
		$SLATE_ARGUMENT(FMargin, TogglePadding, );
		$SLATE_ARGUMENT(FOnConstrainVector, ConstrainVector, );
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

		SNumericVectorInputBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SNumericVectorInputBox> Widget = MakeTDecl<SNumericVectorInputBox>("SNumericVectorInputBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericVectorInputBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SNumericVectorInputBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SNumericVectorInputBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SNumericVectorInputBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SNumericVectorInputBox> Widget = MakeShared<SNumericVectorInputBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SNumericVectorInputBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SNumericVectorInputBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SNumericVectorInputBox");
		Args.Add<TOptional<VectorType>>("Vector", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<VectorType>>("MinVector", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<VectorType>>("MaxVector", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<VectorType>>("MinSliderVector", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<VectorType>>("MaxSliderVector", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnVectorValueChanged>("OnVectorChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnVectorValueCommitted>("OnVectorCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FEditableTextBoxStyle>("EditableTextBoxStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSpinBoxStyle>("SpinBoxStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowSpin", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<NumericType>("SpinDelta", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("bColorAxisLabels", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSimpleDelegate>("OnBeginSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnNumericValueChanged>("OnEndSliderMovement", DTS::EArgType::SLATE_EVENT);
		Args.Add<TSharedPtr< INumericTypeInterface<NumericType> >>("TypeInterface", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("DisplayToggle", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("TogglePadding", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnConstrainVector>("ConstrainVector", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SNumericVectorInputBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SNumericVectorInputBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericVectorInputBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SNumericVectorInputBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SNumericVectorInputBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SNumericVectorInputBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SNumericVectorInputBox()
	{
		GenDTS();
		RegisterTSharedPtr(SNumericVectorInputBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SNumericVectorInputBox::$SNew},
			{"SAssignNew", $SNumericVectorInputBox::$SAssignNew},
			{"MakeShared", $SNumericVectorInputBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SNumericVectorInputBox";
		Def.TypeId = puerts::StaticTypeId<SNumericVectorInputBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SNumericVectorInputBox _AutoRegister_SNumericVectorInputBox;