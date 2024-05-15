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

			v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, "Text")).ToLocalChecked();
			if (JsValue->IsString())
			{
				Arguments._Text = FText::FromString(puerts::FV8Utils::ToFString(Isolate, JsValue));
			}
			else if (JsValue->IsFunction())
			{
				v8::Isolate::Scope IsolateScope(Isolate);
				v8::HandleScope HandleScope(Isolate);
				v8::Context::Scope ContextScope(Context);
				v8::Local<v8::Function> Function = JsValue.As<v8::Function>();

				TAttribute<FText>::FGetter Getter;
				Getter.BindLambda([Function, Context, Isolate]()
					{
						v8::Local<v8::Value> JsRet = Function->Call(Context, v8::Undefined(Isolate), 0, nullptr).ToLocalChecked();
						std::string Ret = puerts::converter::Converter<std::string>::toCpp(Context, JsRet);
						FString String = UTF8_TO_TCHAR(Ret.c_str());
						return FText::FromString(String);
					});
				Arguments._Text.Bind(Getter);
			}

		}

		TSharedPtr<STextBlock> Widget = MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		auto V8Result = puerts::converter::Converter<TSharedPtr<STextBlock>>::toScript(Context, Widget);
		//auto V8Result = puerts::DataTransfer::FindOrAddStruct<TSharedPtr<STextBlock>>(Isolate, Context, &Widget, true);

		//auto V8Result = puerts::DataTransfer::FindOrAddCData(Isolate, Context, puerts::DynamicTypeId<TSharedPtr<STextBlock>>::get(&Widget), &Widget, true);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info) { TSharedPtr<STextBlock> Widget = MakeShared<STextBlock>(); }
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }

	static void GetText(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{

	}
}

struct AutoRegister_STextBlock
{
	void RegisterArguments(WidgetHelper::FArgumentsDTS& Arguments)
	{
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
		REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked(ESlateArgumentType::SLATE_EVENT);
	}

	void GenDTS()
	{
		WidgetHelper::FClassDTS ClassDTS;
		ClassDTS.Name = "STextBlock";
		ClassDTS.Super = "SLeafWidget";
		RegisterArguments(ClassDTS.Arguments);

		ClassDTS.Functions.Add({
				"SNew",
				{
					{ "Arguments", "STextBlock.Arguments" },
					{ "Filename", TS_string }
				},
				{ "UE.TSharedPtr<cpp.STextBlock>" } ,
				true
			});
		ClassDTS.Functions.Add({
				"SAssignNew",
				{
					{ "WidgetRef", "UE.TSharedPtr<cpp.STextBlock>", true },
					{ "Arguments", "STextBlock.Arguments" },
					{ "Filename", TS_string }
				},
				{ "void" } ,
				true
			});
		ClassDTS.Functions.Add({
				"MakeShared",
				{ },
				{ "UE.TSharedPtr<cpp.STextBlock>" } ,
				true
			});
		ClassDTS.Functions.Add({
				"GetText",
				{ },
				{ TS_string }
			});

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