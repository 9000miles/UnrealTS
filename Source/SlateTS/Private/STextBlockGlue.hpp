#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Text/STextBlock.h"
#include "WidgetArgumentHelper.hpp"
#include "TypeInfo.hpp"
#include "WidgetHelper.h"

UsingCppType(STextBlock);
UsingTSharedPtr(STextBlock);
UsingTSharedRef(STextBlock);

namespace $STextBlock
{
	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		if (Info.Length() != 2)
		{
			puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
			return;
		}

		FString Filename;
		if (Info[1]->IsString())
		{
			Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[1])));
		}

		STextBlock::FArguments Arguments;
		//@TODO 实现从Info读取数据，并赋值到Arguments
		if (Info[0]->IsObject())
		{
			v8::Local<v8::Object> JsObject = Info[0].As<v8::Object>();
#if 1
			SET_WIDGET_ARGUMENT_VARIABLE_A(Text);
			SET_WIDGET_ARGUMENT_VARIABLE_A(TextStyle);
			SET_WIDGET_ARGUMENT_VARIABLE_A(Font);
			SET_WIDGET_ARGUMENT_VARIABLE_A(StrikeBrush);
			SET_WIDGET_ARGUMENT_VARIABLE_A(ColorAndOpacity);
			SET_WIDGET_ARGUMENT_VARIABLE_A(ShadowOffset);
			SET_WIDGET_ARGUMENT_VARIABLE_A(ShadowColorAndOpacity);
			SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightColor);
			SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightShape);
			SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightText);
			SET_WIDGET_ARGUMENT_VARIABLE_A(WrapTextAt);
			SET_WIDGET_ARGUMENT_VARIABLE_A(AutoWrapText);
			SET_WIDGET_ARGUMENT_VARIABLE_A(WrappingPolicy);
			SET_WIDGET_ARGUMENT_VARIABLE_A(TransformPolicy);
			SET_WIDGET_ARGUMENT_VARIABLE_A(Margin);
			SET_WIDGET_ARGUMENT_VARIABLE_A(LineHeightPercentage);
			SET_WIDGET_ARGUMENT_VARIABLE_A(Justification);
			SET_WIDGET_ARGUMENT_VARIABLE_A(MinDesiredWidth);
			SET_WIDGET_ARGUMENT_VARIABLE_A(TextShapingMethod);
			SET_WIDGET_ARGUMENT_VARIABLE_A(TextFlowDirection);
			//SET_WIDGET_ARGUMENT_VARIABLE_A(LineBreakPolicy);
			SET_WIDGET_ARGUMENT_VARIABLE_A(OverflowPolicy);
			SET_WIDGET_ARGUMENT_VARIABLE_A(SimpleTextMode);
			//SET_WIDGET_ARGUMENT_VARIABLE_A(OnDoubleClicked);
#else
			const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, "Text")).FromMaybe(false);

			v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, "Text")).ToLocalChecked();
			if (JsValue->IsString())
			{
				Arguments._Text = FText::FromString(puerts::FV8Utils::ToFString(Isolate, JsValue));
			}
			else if (JsValue->IsFunction())
			{
				v8::Local<v8::Function> Function = JsValue.As<v8::Function>();
				FJsObject JsFunction = FJsObject(Context, Function);
				TAttribute<FText>::FGetter Getter;
				Getter.BindLambda([JsFunction]()
					{
						std::string Ret = JsFunction.Func<std::string>(nullptr);
						FString String = UTF8_TO_TCHAR(Ret.c_str());
						return FText::FromString(String);
					});
				Arguments._Text.Bind(Getter);
			}
#endif
		}

		TSharedPtr<STextBlock> Widget = MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		auto V8Result = puerts::converter::Converter<TSharedPtr<STextBlock>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info) { TSharedPtr<STextBlock> Widget = MakeShared<STextBlock>(); }
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }

	static void GetText(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 0)
		{
			auto Self = puerts::converter::Converter<STextBlock*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "[STextBlock::GetText] Attempt to access a NULL self pointer"); return; }

			auto MethodResult = Self->GetText();
			auto V8Result = puerts::converter::Converter<FText>::toScript(Context, MethodResult);
			Info.GetReturnValue().Set(V8Result); return;
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void SetText(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 1)
		{
			auto Self = puerts::converter::Converter<STextBlock*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "[STextBlock::GetText] Attempt to access a NULL self pointer"); return; }

			v8::Local<v8::Value> JsObject = Info[0].As<v8::Value>();
			auto Ret = WidgetAttribute4::MakeAttribute<FText>(Context, JsObject, "");
			Self->SetText(Ret); return;
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
}

struct AutoRegister_STextBlock
{
	DTS::WidgetArguments RegisterArguments()
	{
		DTS::WidgetArguments Arguments;
		Arguments.Name = "STextBlock";
		REGISTER_WIDGET_ARGUMENT_TYPE__Text(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle(ESlateArgumentType::SLATE_STYLE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__Font(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__Margin(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__Justification(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection(ESlateArgumentType::SLATE_ARGUMENT);
		//REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked(ESlateArgumentType::SLATE_EVENT);
		return Arguments;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STextBlock").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Properties(DTS::Array<DTS::Property>()
				+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
				+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
			)
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("GetText")
						.Return(DTS::Property().Type(TS_string))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SetText")
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Text").Type(puerts::ScriptTypeName<TAttribute<FText>>::value().Data())
						)
				]
			);

		GenWidgetDTS.Add(ClassDTS);
	}

	AutoRegister_STextBlock()
	{
		GenDTS();
		RegisterTSharedPtr(STextBlock);


		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{"GetText", $STextBlock::GetText},
			{"SetText", $STextBlock::SetText},
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STextBlock::$SNew},
			{"SAssignNew", $STextBlock::$SAssignNew},
			{"MakeShared", $STextBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STextBlock";
		Def.TypeId = puerts::StaticTypeId<STextBlock>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STextBlock _AutoRegister_STextBlock;