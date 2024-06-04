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

UsingCppType(SMenuAnchor);
UsingTSharedPtr(SMenuAnchor);

namespace $SMenuAnchor
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SMenuAnchor::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_DEFAULT_SLOT(Content);
		$SLATE_ARGUMENT(Padding);
		$SLATE_ARGUMENT(MenuContent);
		$SLATE_EVENT(OnGetMenuContent);
		$SLATE_EVENT(OnMenuOpenChanged);
		$SLATE_ATTRIBUTE(Placement);
		$SLATE_ARGUMENT(FitInWindow);
		$SLATE_ARGUMENT(Method);
		$SLATE_ARGUMENT(ShouldDeferPaintingAfterWindowContent);
		$SLATE_ARGUMENT(UseApplicationMenuStack);
		$SLATE_ARGUMENT(IsCollapsedByParent);
		$SLATE_ARGUMENT(ApplyWidgetStyleToMenu);
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

		SMenuAnchor::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SMenuAnchor> Widget = MakeTDecl<SMenuAnchor>("SMenuAnchor", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SMenuAnchor>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SMenuAnchor>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SMenuAnchor>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SMenuAnchor>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SMenuAnchor> Widget = MakeShared<SMenuAnchor>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SMenuAnchor>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SMenuAnchor
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SMenuAnchor");
		Args.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<TSharedPtr<SWidget>>("MenuContent", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnIsOpenChanged>("OnMenuOpenChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<EMenuPlacement>("Placement", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("FitInWindow", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<EPopupMethod>>("Method", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShouldDeferPaintingAfterWindowContent", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("UseApplicationMenuStack", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsCollapsedByParent", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ApplyWidgetStyleToMenu", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SMenuAnchor").Super("SPanel")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SMenuAnchor.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SMenuAnchor.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SMenuAnchor()
	{
		GenDTS();
		RegisterTSharedPtr(SMenuAnchor);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SMenuAnchor::$SNew},
			{"SAssignNew", $SMenuAnchor::$SAssignNew},
			{"MakeShared", $SMenuAnchor::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SMenuAnchor";
		Def.TypeId = puerts::StaticTypeId<SMenuAnchor>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SPanel>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SMenuAnchor _AutoRegister_SMenuAnchor;