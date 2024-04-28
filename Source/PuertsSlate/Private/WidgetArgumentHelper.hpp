#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		if (Descriptor->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.Text(FText::FromString(TextString));
		}
		else if (Descriptor->IsFunction())
		{
			auto Func = JsObject.Get<std::function<char* ()>>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Func]() { const char* Result = Func(); return Result ? FText::FromString(Result) : FText(); });
			Arguments._Text.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
		Arguments.HighlightText(FText::FromString(TextString));
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		FSlateColor ColorAndOpacity = JsObject.Get<FSlateColor>(VariableName);
		Arguments.ColorAndOpacity(ColorAndOpacity);
	}
	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

	void Set_OnClicked1(SButton::FArguments& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (JsObject.Has(VariableName, Descriptor))
		{
			auto ClickFunc = JsObject.Get<std::function<void()>>(VariableName);
			//FOnClicked  Delegate = FOnClicked::CreateLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments.OnClicked_Lambda(Delegate);
			//Arguments.OnClicked_Lambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			Arguments._OnClicked.BindLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments._OnClicked= Delegate;
		};
	}

};