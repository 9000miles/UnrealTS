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
#include "Widgets/Views/SHeaderRow.h"

UsingCppType(SHeaderRow);
UsingTSharedPtr(SHeaderRow);

namespace $SHeaderRow
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SHeaderRow::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(FName, ColumnId, );
		$SLATE_ATTRIBUTE(FText, DefaultLabel, );
		$SLATE_ATTRIBUTE(FText, DefaultTooltip, );
		$SLATE_ATTRIBUTE(TSharedPtr< IToolTip >, ToolTip, );
		$SLATE_ATTRIBUTE(float, FillWidth, );
		$SLATE_ARGUMENT(TOptional< float >, FixedWidth, );
		$SLATE_ATTRIBUTE(float, ManualWidth, );
		$SLATE_ARGUMENT(TOptional< float >, FillSized, );
		//$SLATE_EVENT(FOnWidthChanged, OnWidthChanged, );
		$SLATE_DEFAULT_SLOT(FArguments, HeaderContent, );
		$SLATE_ARGUMENT(EHorizontalAlignment, HAlignHeader, );
		$SLATE_ARGUMENT(EVerticalAlignment, VAlignHeader, );
		$SLATE_ARGUMENT(TOptional< FMargin >, HeaderContentPadding, );
		$SLATE_ARGUMENT(EHeaderComboVisibility, HeaderComboVisibility, );
		$SLATE_NAMED_SLOT(FArguments, MenuContent, );
		//$SLATE_EVENT(FOnGetContent, OnGetMenuContent, );
		$SLATE_ARGUMENT(EHorizontalAlignment, HAlignCell, );
		$SLATE_ARGUMENT(EVerticalAlignment, VAlignCell, );
		$SLATE_ATTRIBUTE(EColumnSortMode::Type, InitialSortMode, );
		$SLATE_ATTRIBUTE(EColumnSortMode::Type, SortMode, );
		$SLATE_ATTRIBUTE(EColumnSortPriority::Type, SortPriority, );
		//$SLATE_EVENT(FOnSortModeChanged, OnSort, );
		$SLATE_ATTRIBUTE(bool, ShouldGenerateWidget, );
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

		SHeaderRow::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SHeaderRow> Widget = MakeTDecl<SHeaderRow>("SHeaderRow", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SHeaderRow>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SHeaderRow>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SHeaderRow>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SHeaderRow>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SHeaderRow> Widget = MakeShared<SHeaderRow>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SHeaderRow>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SHeaderRow
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SHeaderRow");
		Args.Add<FName>("ColumnId", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("DefaultLabel", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("DefaultTooltip", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr< IToolTip >>("ToolTip", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("FillWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< float >>("FixedWidth", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("ManualWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional< float >>("FillSized", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnWidthChanged>("OnWidthChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FArguments>("HeaderContent", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<EHorizontalAlignment>("HAlignHeader", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVerticalAlignment>("VAlignHeader", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional< FMargin >>("HeaderContentPadding", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EHeaderComboVisibility>("HeaderComboVisibility", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FArguments>("MenuContent", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_EVENT);
		Args.Add<EHorizontalAlignment>("HAlignCell", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVerticalAlignment>("VAlignCell", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EColumnSortMode::Type>("InitialSortMode", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EColumnSortMode::Type>("SortMode", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EColumnSortPriority::Type>("SortPriority", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnSortModeChanged>("OnSort", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("ShouldGenerateWidget", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SHeaderRow").Super("SBorder")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SHeaderRow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SHeaderRow>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SHeaderRow>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SHeaderRow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SHeaderRow>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SHeaderRow()
	{
		GenDTS();
		RegisterTSharedPtr(SHeaderRow);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SHeaderRow::$SNew},
			{"SAssignNew", $SHeaderRow::$SAssignNew},
			{"MakeShared", $SHeaderRow::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SHeaderRow";
		Def.TypeId = puerts::StaticTypeId<SHeaderRow>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SBorder>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SHeaderRow _AutoRegister_SHeaderRow;