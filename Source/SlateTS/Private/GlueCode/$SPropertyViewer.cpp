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
//#include "AdvancedWidgets/Public/Widgets/PropertyViewer/SPropertyViewer.h"
//
//UsingCppType(SPropertyViewer);
//UsingTSharedPtr(SPropertyViewer);
//
//namespace $SPropertyViewer
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SPropertyViewer::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		$SLATE_ARGUMENT_DEFAULT(EPropertyVisibility, PropertyVisibility, );
//		$SLATE_ARGUMENT_DEFAULT(bool, bSanitizeName, );
//		$SLATE_ARGUMENT_DEFAULT(bool, bShowFieldIcon, );
//		$SLATE_ARGUMENT_DEFAULT(bool, bSortChildNode, );
//		$SLATE_ARGUMENT_DEFAULT(bool, bShowSearchBox, );
//		$SLATE_ARGUMENT_DEFAULT(ESelectionMode::Type, SelectionMode, );
//		$SLATE_ARGUMENT_DEFAULT(IFieldIterator*, FieldIterator, );
//		$SLATE_ARGUMENT_DEFAULT(IFieldExpander*, FieldExpander, );
//		$SLATE_ARGUMENT_DEFAULT(INotifyHook*, NotifyHook, );
//		$SLATE_NAMED_SLOT(FArguments, SearchBoxPreSlot, );
//		$SLATE_NAMED_SLOT(FArguments, SearchBoxPostSlot, );
//		//$SLATE_EVENT(FGetFieldWidget, OnGetPreSlot, );
//		//$SLATE_EVENT(FGetFieldWidget, OnGetPostSlot, );
//		//$SLATE_EVENT(FOnContextMenuOpening, OnContextMenuOpening, );
//		//$SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged, );
//		//$SLATE_EVENT(FOnDoubleClicked, OnDoubleClicked, );
//		//$SLATE_EVENT(FOnGenerateContainer, OnGenerateContainer, );
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
//		SPropertyViewer::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SPropertyViewer> Widget = MakeTDecl<SPropertyViewer>("SPropertyViewer", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SPropertyViewer>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SPropertyViewer>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SPropertyViewer>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SPropertyViewer>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SPropertyViewer> Widget = MakeShared<SPropertyViewer>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SPropertyViewer>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SPropertyViewer
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SPropertyViewer");
//		Args.Add<EPropertyVisibility>("PropertyVisibility", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<bool>("bSanitizeName", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<bool>("bShowFieldIcon", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<bool>("bSortChildNode", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<bool>("bShowSearchBox", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<ESelectionMode::Type>("SelectionMode", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<IFieldIterator*>("FieldIterator", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<IFieldExpander*>("FieldExpander", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<INotifyHook*>("NotifyHook", DTS::EArgType::SLATE_ARGUMENT_DEFAULT);
//		Args.Add<FArguments>("SearchBoxPreSlot", DTS::EArgType::SLATE_NAMED_SLOT);
//		Args.Add<FArguments>("SearchBoxPostSlot", DTS::EArgType::SLATE_NAMED_SLOT);
//		Args.Add<FGetFieldWidget>("OnGetPreSlot", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FGetFieldWidget>("OnGetPostSlot", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnContextMenuOpening>("OnContextMenuOpening", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnSelectionChanged>("OnSelectionChanged", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnDoubleClicked>("OnDoubleClicked", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnGenerateContainer>("OnGenerateContainer", DTS::EArgType::SLATE_EVENT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SPropertyViewer").Super("SCompoundWidget")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SPropertyViewer.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SPropertyViewer>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SPropertyViewer>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SPropertyViewer.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SPropertyViewer>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SPropertyViewer()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SPropertyViewer);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SPropertyViewer::$SNew},
//			{"SAssignNew", $SPropertyViewer::$SAssignNew},
//			{"MakeShared", $SPropertyViewer::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SPropertyViewer";
//		Def.TypeId = puerts::StaticTypeId<SPropertyViewer>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SPropertyViewer _AutoRegister_SPropertyViewer;