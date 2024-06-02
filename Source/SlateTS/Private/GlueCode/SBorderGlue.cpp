#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "PuertsEx.h"

#include "Widgets/Layout/SBorder.h"
#include "DTSDefine.h"

UsingCppType(SBorder);
UsingTSharedPtr(SBorder);

namespace $SBorder
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SBorder::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		SET_WIDGET_ARGUMENT_VARIABLE(Content);
		SET_WIDGET_ARGUMENT_VARIABLE(HAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(VAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(Padding);
		SET_WIDGET_ARGUMENT_VARIABLE(OnMouseButtonDown);
		SET_WIDGET_ARGUMENT_VARIABLE(OnMouseButtonUp);
		SET_WIDGET_ARGUMENT_VARIABLE(OnMouseMove);
		SET_WIDGET_ARGUMENT_VARIABLE(OnMouseDoubleClick);
		SET_WIDGET_ARGUMENT_VARIABLE(BorderImage);
		SET_WIDGET_ARGUMENT_VARIABLE(ContentScale);
		SET_WIDGET_ARGUMENT_VARIABLE(DesiredSizeScale);
		SET_WIDGET_ARGUMENT_VARIABLE_WITH_TYPE(ColorAndOpacity, FLinearColor);
		SET_WIDGET_ARGUMENT_VARIABLE(BorderBackgroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(ForegroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(ShowEffectWhenDisabled);
		SET_WIDGET_ARGUMENT_VARIABLE(FlipForRightToLeftFlowDirection);
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

		SBorder::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SBorder> Widget = MakeTDecl<SBorder>("SBorder", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SBorder>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SBorder>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SBorder>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SBorder>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SBorder> Widget = MakeShared<SBorder>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SBorder>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SBorder
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SBorder");
		DTSArgs.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		DTSArgs.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FPointerEventHandler>("OnMouseButtonDown", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FPointerEventHandler>("OnMouseButtonUp", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FPointerEventHandler>("OnMouseMove", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FPointerEventHandler>("OnMouseDoubleClick", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<const FSlateBrush*>("BorderImage", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FVector2D>("ContentScale", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FVector2D>("DesiredSizeScale", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FLinearColor>("ColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("BorderBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<bool>("ShowEffectWhenDisabled", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<bool>("FlipForRightToLeftFlowDirection", DTS::EArgType::SLATE_ARGUMENT);
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SBorder").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SBorder.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBorder>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SBorder>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SBorder.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBorder>>::value().Data()))
				]
			);

		GenClassDTS.Add(ClassDTS);
	}

	AutoRegister_SBorder()
	{
		GenDTS();
		RegisterTSharedPtr(SBorder);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SBorder::$SNew},
			{"SAssignNew", $SBorder::$SAssignNew},
			{"MakeShared", $SBorder::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SBorder";
		Def.TypeId = puerts::StaticTypeId<SBorder>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SBorder _AutoRegister_SBorder;