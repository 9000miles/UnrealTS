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

UsingCppType(STableRow);
UsingTSharedPtr(STableRow);

namespace $STableRow
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, STableRow::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FTableRowStyle, Style, FTableRowStyle);
		$SLATE_ARGUMENT(const ISlateStyle*, ExpanderStyleSet, );
		//$SLATE_EVENT(FOnCanAcceptDrop, OnCanAcceptDrop, );
		//$SLATE_EVENT(FOnAcceptDrop, OnAcceptDrop, );
		//$SLATE_EVENT(FOnPaintDropIndicator, OnPaintDropIndicator, );
		//$SLATE_EVENT(FOnDragDetected, OnDragDetected, );
		//$SLATE_EVENT(FOnTableRowDragEnter, OnDragEnter, );
		//$SLATE_EVENT(FOnTableRowDragLeave, OnDragLeave, );
		//$SLATE_EVENT(FOnTableRowDrop, OnDrop, );
		$SLATE_ATTRIBUTE(FMargin, Padding, );
		$SLATE_ARGUMENT(bool, ShowSelection, );
		$SLATE_ARGUMENT(bool, ShowWires, );
		$SLATE_ARGUMENT(bool, bAllowPreselectedItemActivation, );
		$SLATE_ARGUMENT(ETableRowSignalSelectionMode, SignalSelectionMode, );
		$SLATE_DEFAULT_SLOT(typename STableRow<ItemType>::FArguments, Content, );
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

		STableRow::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<STableRow> Widget = MakeTDecl<STableRow>("STableRow", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<STableRow>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<STableRow>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<STableRow>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<STableRow>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<STableRow> Widget = MakeShared<STableRow>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<STableRow>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_STableRow
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("STableRow");
		Args.Add<FTableRowStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<const ISlateStyle*>("ExpanderStyleSet", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnCanAcceptDrop>("OnCanAcceptDrop", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnAcceptDrop>("OnAcceptDrop", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnPaintDropIndicator>("OnPaintDropIndicator", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDragDetected>("OnDragDetected", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTableRowDragEnter>("OnDragEnter", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTableRowDragLeave>("OnDragLeave", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTableRowDrop>("OnDrop", DTS::EArgType::SLATE_EVENT);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ShowSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowWires", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("bAllowPreselectedItemActivation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<ETableRowSignalSelectionMode>("SignalSelectionMode", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<typename STableRow<ItemType>::FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STableRow").Super("ITableRow")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STableRow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STableRow>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STableRow>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STableRow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STableRow>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_STableRow()
	{
		GenDTS();
		RegisterTSharedPtr(STableRow);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STableRow::$SNew},
			{"SAssignNew", $STableRow::$SAssignNew},
			{"MakeShared", $STableRow::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STableRow";
		Def.TypeId = puerts::StaticTypeId<STableRow>::get();
		Def.SuperTypeId = puerts::StaticTypeId<ITableRow>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STableRow _AutoRegister_STableRow;