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

UsingCppType(STreeView);
UsingTSharedPtr(STreeView);

namespace $STreeView
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, STreeView::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FTableViewStyle, TreeViewStyle, );
		$SLATE_EVENT(FOnGenerateRow, OnGenerateRow, );
		$SLATE_EVENT(FOnGenerateRow, OnGeneratePinnedRow, );
		$SLATE_EVENT(FOnWidgetToBeRemoved, OnRowReleased, );
		$SLATE_EVENT(FOnTableViewScrolled, OnTreeViewScrolled, );
		$SLATE_EVENT(FOnItemScrolledIntoView, OnItemScrolledIntoView, );
		$SLATE_EVENT(FOnGetChildren, OnGetChildren, );
		$SLATE_EVENT(FOnSetExpansionRecursive, OnSetExpansionRecursive, );
		$SLATE_ARGUMENT(const TArray<ItemType>*, TreeItemsSource, );
		$SLATE_ATTRIBUTE(float, ItemHeight, );
		$SLATE_ATTRIBUTE(int32, MaxPinnedItems, );
		$SLATE_EVENT(FOnContextMenuOpening, OnContextMenuOpening, );
		$SLATE_EVENT(FOnMouseButtonClick, OnMouseButtonClick, );
		$SLATE_EVENT(FOnMouseButtonDoubleClick, OnMouseButtonDoubleClick, );
		$SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged, );
		$SLATE_EVENT(FOnExpansionChanged, OnExpansionChanged, );
		$SLATE_EVENT(FIsSelectableOrNavigable, OnIsSelectableOrNavigable, );
		$SLATE_ATTRIBUTE(ESelectionMode::Type, SelectionMode, );
		$SLATE_ARGUMENT(TSharedPtr<SHeaderRow>, HeaderRow, );
		$SLATE_ARGUMENT(TSharedPtr<SScrollBar>, ExternalScrollbar, );
		$SLATE_ARGUMENT(bool, EnableAnimatedScrolling, );
		$SLATE_ARGUMENT(TOptional<double>, FixedLineScrollOffset, );
		$SLATE_ARGUMENT(EFocusCause, ScrollbarDragFocusCause, );
		$SLATE_ARGUMENT(EConsumeMouseWheel, ConsumeMouseWheel, );
		$SLATE_ARGUMENT(EAllowOverscroll, AllowOverscroll, );
		$SLATE_STYLE_ARGUMENT(FScrollBarStyle, ScrollBarStyle, );
		$SLATE_ARGUMENT(bool, PreventThrottling, );
		$SLATE_ARGUMENT(float, WheelScrollMultiplier, );
		$SLATE_EVENT(FOnItemToString_Debug, OnItemToString_Debug, );
		$SLATE_EVENT(FOnTableViewBadState, OnEnteredBadState, );
		$SLATE_ARGUMENT(bool, HandleGamepadEvents, );
		$SLATE_ARGUMENT(bool, HandleDirectionalNavigation, );
		$SLATE_ARGUMENT(bool, AllowInvisibleItemSelection, );
		$SLATE_ARGUMENT(bool, HighlightParentNodesForSelection, );
		$SLATE_ARGUMENT(bool, ReturnFocusToSelection, );
		$SLATE_ATTRIBUTE(bool, ShouldStackHierarchyHeaders, );
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

		STreeView::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<STreeView> Widget = MakeTDecl<STreeView>("STreeView", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<STreeView>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<STreeView>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<STreeView>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<STreeView>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<STreeView> Widget = MakeShared<STreeView>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<STreeView>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_STreeView
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("STreeView");
		Args.Add<FTableViewStyle>("TreeViewStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FOnGenerateRow>("OnGenerateRow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGenerateRow>("OnGeneratePinnedRow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnWidgetToBeRemoved>("OnRowReleased", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTableViewScrolled>("OnTreeViewScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnItemScrolledIntoView>("OnItemScrolledIntoView", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGetChildren>("OnGetChildren", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSetExpansionRecursive>("OnSetExpansionRecursive", DTS::EArgType::SLATE_EVENT);
		Args.Add<const TArray<ItemType>*>("TreeItemsSource", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("ItemHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<int32>("MaxPinnedItems", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnContextMenuOpening>("OnContextMenuOpening", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnMouseButtonClick>("OnMouseButtonClick", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnMouseButtonDoubleClick>("OnMouseButtonDoubleClick", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSelectionChanged>("OnSelectionChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnExpansionChanged>("OnExpansionChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FIsSelectableOrNavigable>("OnIsSelectableOrNavigable", DTS::EArgType::SLATE_EVENT);
		Args.Add<ESelectionMode::Type>("SelectionMode", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr<SHeaderRow>>("HeaderRow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr<SScrollBar>>("ExternalScrollbar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("EnableAnimatedScrolling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<double>>("FixedLineScrollOffset", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EFocusCause>("ScrollbarDragFocusCause", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EConsumeMouseWheel>("ConsumeMouseWheel", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EAllowOverscroll>("AllowOverscroll", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FScrollBarStyle>("ScrollBarStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<bool>("PreventThrottling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("WheelScrollMultiplier", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnItemToString_Debug>("OnItemToString_Debug", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTableViewBadState>("OnEnteredBadState", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("HandleGamepadEvents", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("HandleDirectionalNavigation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AllowInvisibleItemSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("HighlightParentNodesForSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ReturnFocusToSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShouldStackHierarchyHeaders", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STreeView").Super("SListView")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STreeView.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STreeView>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STreeView>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STreeView.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STreeView>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_STreeView()
	{
		GenDTS();
		RegisterTSharedPtr(STreeView);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STreeView::$SNew},
			{"SAssignNew", $STreeView::$SAssignNew},
			{"MakeShared", $STreeView::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STreeView";
		Def.TypeId = puerts::StaticTypeId<STreeView>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SListView>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STreeView _AutoRegister_STreeView;