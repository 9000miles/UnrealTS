#include "CoreMinimal.h"
#include "JsObject.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		if (JsObject.Has(VariableName))
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.Text(FText::FromString(TextString));
		};
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		if (JsObject.Has(VariableName))
		{
			FSlateColor ColorAndOpacity = JsObject.Get<FSlateColor>(VariableName);
			Arguments.ColorAndOpacity(ColorAndOpacity);
		};
	}
	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		if (JsObject.Has(VariableName))
		{
			auto ClickFunc = JsObject.Get<std::function<void()>>(VariableName);
			//FOnClicked  Delegate = FOnClicked::CreateLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
					//Arguments.OnClicked_Lambda(Delegate);
					//Arguments.OnClicked_Lambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			Arguments._OnClicked.BindLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments._OnClicked= Delegate;
		};
	}

	void Set_OnClicked1(SButton::FArguments& Arguments, FJsObject JsObject, const char* VariableName)
	{
		if (JsObject.Has(VariableName))
		{
			auto ClickFunc = JsObject.Get<std::function<void()>>(VariableName);
			//FOnClicked  Delegate = FOnClicked::CreateLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments.OnClicked_Lambda(Delegate);
			//Arguments.OnClicked_Lambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			Arguments._OnClicked.BindLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments._OnClicked= Delegate;
		};
	}

}