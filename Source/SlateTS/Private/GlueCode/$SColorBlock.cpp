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
#include "Widgets/Colors/SColorBlock.h"

UsingCppType(SColorBlock);
UsingTSharedPtr(SColorBlock);

namespace $SColorBlock
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SColorBlock::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FLinearColor, Color, );
		$SLATE_ATTRIBUTE(const FSlateBrush*, AlphaBackgroundBrush, );
		$SLATE_ATTRIBUTE(FVector4, CornerRadius, );
		$SLATE_ATTRIBUTE(bool, ColorIsHSV, );
		$SLATE_ATTRIBUTE(bool, ShowBackgroundForAlpha, );
		$SLATE_ATTRIBUTE(bool, UseSRGB, );
		$SLATE_ATTRIBUTE(EColorBlockAlphaDisplayMode, AlphaDisplayMode, );
		$SLATE_ATTRIBUTE(FVector2D, Size, );
		//$SLATE_EVENT(FPointerEventHandler, OnMouseButtonDown, );
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

		SColorBlock::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SColorBlock> Widget = MakeTDecl<SColorBlock>("SColorBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SColorBlock>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SColorBlock>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SColorBlock>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SColorBlock>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SColorBlock> Widget = MakeShared<SColorBlock>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SColorBlock>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SColorBlock
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SColorBlock");
		Args.Add<FLinearColor>("Color", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("AlphaBackgroundBrush", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FVector4>("CornerRadius", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ColorIsHSV", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ShowBackgroundForAlpha", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("UseSRGB", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EColorBlockAlphaDisplayMode>("AlphaDisplayMode", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FVector2D>("Size", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FPointerEventHandler>("OnMouseButtonDown", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SColorBlock").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SColorBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SColorBlock>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SColorBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorBlock>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SColorBlock()
	{
		GenDTS();
		RegisterTSharedPtr(SColorBlock);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SColorBlock::$SNew},
			{"SAssignNew", $SColorBlock::$SAssignNew},
			{"MakeShared", $SColorBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SColorBlock";
		Def.TypeId = puerts::StaticTypeId<SColorBlock>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SColorBlock _AutoRegister_SColorBlock;