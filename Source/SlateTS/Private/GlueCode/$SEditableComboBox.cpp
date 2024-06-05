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

UsingCppType(SEditableComboBox);
UsingTSharedPtr(SEditableComboBox);

namespace $SEditableComboBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SEditableComboBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FText, AddButtonToolTip, );
		$SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
		$SLATE_NAMED_SLOT(FArguments, Content, );
		$SLATE_ATTRIBUTE(FMargin, ContentPadding, );
		$SLATE_ARGUMENT(OptionType, InitiallySelectedItem, );
		$SLATE_ARGUMENT(float, MaxListHeight, );
		$SLATE_ARGUMENT(EVisibility, IsRenameVisible, );
		$SLATE_EVENT(FOnClicked, OnAddClicked, );
		$SLATE_EVENT(FOnGenerateWidget, OnGenerateWidget, );
		$SLATE_EVENT(FOnGetEditableComboBoxText, OnGetEditableText, );
		$SLATE_EVENT(FOnClicked, OnRemoveClicked, );
		$SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged, );
		$SLATE_EVENT(FOnTextCommitted, OnSelectionRenamed, );
		$SLATE_ARGUMENT(const TArray<OptionType>*, OptionsSource, );
		$SLATE_ATTRIBUTE(FText, RemoveButtonToolTip, );
		$SLATE_ATTRIBUTE(FText, RenameButtonToolTip, );
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

		SEditableComboBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SEditableComboBox> Widget = MakeTDecl<SEditableComboBox>("SEditableComboBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SEditableComboBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SEditableComboBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SEditableComboBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SEditableComboBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SEditableComboBox> Widget = MakeShared<SEditableComboBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SEditableComboBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SEditableComboBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SEditableComboBox");
		Args.Add<FText>("AddButtonToolTip", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<OptionType>("InitiallySelectedItem", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MaxListHeight", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVisibility>("IsRenameVisible", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnClicked>("OnAddClicked", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGenerateWidget>("OnGenerateWidget", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGetEditableComboBoxText>("OnGetEditableText", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnClicked>("OnRemoveClicked", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSelectionChanged>("OnSelectionChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnSelectionRenamed", DTS::EArgType::SLATE_EVENT);
		Args.Add<const TArray<OptionType>*>("OptionsSource", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("RemoveButtonToolTip", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("RenameButtonToolTip", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SEditableComboBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SEditableComboBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEditableComboBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SEditableComboBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SEditableComboBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEditableComboBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SEditableComboBox()
	{
		GenDTS();
		RegisterTSharedPtr(SEditableComboBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SEditableComboBox::$SNew},
			{"SAssignNew", $SEditableComboBox::$SAssignNew},
			{"MakeShared", $SEditableComboBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SEditableComboBox";
		Def.TypeId = puerts::StaticTypeId<SEditableComboBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SEditableComboBox _AutoRegister_SEditableComboBox;