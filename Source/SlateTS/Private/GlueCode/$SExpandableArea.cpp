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
#include "Widgets/Layout/SExpandableArea.h"

UsingCppType(SExpandableArea);
UsingTSharedPtr(SExpandableArea);

namespace $SExpandableArea
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SExpandableArea::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT_WITH_TYPE(Style, FExpandableAreaStyle);
		$SLATE_ATTRIBUTE(BorderBackgroundColor);
		$SLATE_ATTRIBUTE(BorderImage);
		$SLATE_ATTRIBUTE(BodyBorderBackgroundColor);
		$SLATE_ARGUMENT(BodyBorderImage);
		$SLATE_NAMED_SLOT(HeaderContent);
		$SLATE_NAMED_SLOT(BodyContent);
		$SLATE_ATTRIBUTE(AreaTitle);
		$SLATE_ARGUMENT(InitiallyCollapsed);
		$SLATE_ARGUMENT(MinWidth);
		$SLATE_ARGUMENT(MaxHeight);
		$SLATE_ATTRIBUTE(AreaTitlePadding);
		$SLATE_ATTRIBUTE(HeaderPadding);
		$SLATE_ATTRIBUTE(Padding);
		$SLATE_EVENT(OnAreaExpansionChanged);
		$SLATE_ATTRIBUTE(AreaTitleFont);
		$SLATE_ATTRIBUTE(HeaderCursor);
		$SLATE_ARGUMENT(AllowAnimatedTransition);
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

		SExpandableArea::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SExpandableArea> Widget = MakeTDecl<SExpandableArea>("SExpandableArea", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SExpandableArea>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SExpandableArea>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SExpandableArea>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SExpandableArea>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SExpandableArea> Widget = MakeShared<SExpandableArea>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SExpandableArea>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SExpandableArea
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SExpandableArea");
		Args.Add<FExpandableAreaStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateColor>("BorderBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BorderImage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("BodyBorderBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BodyBorderImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FArguments>("HeaderContent", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FArguments>("BodyContent", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FText>("AreaTitle", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("InitiallyCollapsed", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MinWidth", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MaxHeight", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("AreaTitlePadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("HeaderPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnBooleanValueChanged>("OnAreaExpansionChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSlateFontInfo>("AreaTitleFont", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<EMouseCursor::Type>>("HeaderCursor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowAnimatedTransition", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SExpandableArea").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SExpandableArea.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SExpandableArea>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SExpandableArea>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SExpandableArea.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SExpandableArea>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SExpandableArea()
	{
		GenDTS();
		RegisterTSharedPtr(SExpandableArea);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SExpandableArea::$SNew},
			{"SAssignNew", $SExpandableArea::$SAssignNew},
			{"MakeShared", $SExpandableArea::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SExpandableArea";
		Def.TypeId = puerts::StaticTypeId<SExpandableArea>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SExpandableArea _AutoRegister_SExpandableArea;