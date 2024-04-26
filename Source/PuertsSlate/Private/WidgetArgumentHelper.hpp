#include "CoreMinimal.h"
#include "JsObject.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(_Arguments, Arguments, #Name);

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(const TArgumentType& _Argument, FJsObject Arguments, const char* VariableName)
	{
		if (Arguments.Has(VariableName))
		{
			FString TextString = FString(Arguments.Get<std::string>(VariableName).c_str());
			_Arguments.Text(FText::FromString(TextString));
		};
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(const TArgumentType& _Argument, FJsObject Arguments, const char* Name)
	{
		if (Arguments.Has(VariableName))
		{
			FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>(VariableName);
			_Arguments.ColorAndOpacity(ColorAndOpacity);
		};
	}
}