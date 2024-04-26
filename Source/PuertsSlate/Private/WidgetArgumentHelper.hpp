#include "CoreMinimal.h"
#include "JsObject.h"
#include "Widgets/Text/STextBlock.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(_Arguments, Arguments, #Name);

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& _Argument, FJsObject Arguments, const char* VariableName)
	{
		if (Arguments.Has(VariableName))
		{
			FString TextString = FString(Arguments.Get<std::string>(VariableName).c_str());
			_Argument.Text(FText::FromString(TextString));
		};
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(const TArgumentType& _Argument, FJsObject Arguments, const char* VariableName)
	{
		if (Arguments.Has(VariableName))
		{
			FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>(VariableName);
			_Argument.ColorAndOpacity(ColorAndOpacity);
		};
	}
}