#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument3::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
#define SET_ATTRIBUTE(Name, Type)\
	v8::Local<v8::Value> Value;\
	if (!JsObject.Has(VariableName, Value)) return;\
	v8::Local<v8::Object> Object = Value.As<v8::Object>();\
	FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);\
	Arguments._##Name = WidgetAttribute2::MakeAttribute<Type>(JsValue);

	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(Text, FText);
	}
	template<typename TArgumentType>
	void Set_TextStyle(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}


	template<typename TArgumentType>
	void Set_Font(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//v8::Local<v8::Value> Value;
		//if (!JsObject.Has(VariableName, Value)) return;

		//v8::Local<v8::Object> Object = Value.As<v8::Object>();
		//FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);

		//Arguments._Font = WidgetAttribute2::MakeAttribute<FSlateFontInfo>(JsValue);

		SET_ATTRIBUTE(Font, FSlateFontInfo);
	}
	template<typename TArgumentType>
	void Set_StrikeBrush(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//SET_ATTRIBUTE(StrikeBrush, FSlateBrush*);
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			std::string std_str = JsObject.Get<std::string>(VariableName);
			FColor Color = StringConverter::Converter<FColor>(std_str);
			Arguments.ColorAndOpacity(Color);
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FSlateColor>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					FSlateColor ColorRet = Function.Func_CallBack<FSlateColor>([](v8::Local<v8::Context> Context, v8::Local<v8::Value> MaybeRet)
						{
							if (MaybeRet->IsString())
							{
								std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet);
								FColor Color = StringConverter::Converter<FColor>(std_str);
								return FSlateColor(Color);
							}
							if (MaybeRet->IsObject())
							{
								// @TODO 判断对象类型，是否是FLinearColor实例
								FLinearColor LinearColor = puerts::converter::Converter<FLinearColor>::toCpp(Context, MaybeRet);
								return FSlateColor(LinearColor);

								// 如果不是则从{ R: number, G: number, B:number, A: number }取值
							}

							return FSlateColor();
						});

					return ColorRet;
				});
			Arguments._ColorAndOpacity.Bind(Getter);
		}
		else if (Value->IsObject())
		{
			FLinearColor ColorAndOpacity = JsObject.Get<FLinearColor>(VariableName);
			Arguments.ColorAndOpacity(ColorAndOpacity);
		}
	}
	template<typename TArgumentType>
	void Set_ShadowOffset(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		v8::Local<v8::Object> Object = Value.As<v8::Object>();
		FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);

		Arguments._ShadowOffset = WidgetAttribute2::MakeAttribute<FVector2D>(JsValue);
		return;
	}
	template<typename TArgumentType>
	void Set_ShadowColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightColor(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightShape(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_WrapTextAt(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		v8::Local<v8::Object> Object = Value.As<v8::Object>();
		FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);

		Arguments._WrapTextAt = WidgetAttribute2::MakeAttribute<float>(JsValue);
	}
	template<typename TArgumentType>
	void Set_AutoWrapText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		v8::Local<v8::Object> Object = Value.As<v8::Object>();
		FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);

		Arguments._AutoWrapText = WidgetAttribute2::MakeAttribute<bool>(JsValue);
		return;
	}
	template<typename TArgumentType>
	void Set_WrappingPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TransformPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_Margin(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_LineHeightPercentage(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_Justification(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_MinDesiredWidth(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TextShapingMethod(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TextFlowDirection(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_LineBreakPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_OverflowPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_SimpleTextMode(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_OnDoubleClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}



	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

};


namespace WidgetArgument2
{
#define SET_ATTRIBUTE(Name, Type)\
	v8::Local<v8::Value> Value;\
	if (!JsObject.Has(VariableName, Value)) return;\
	v8::Local<v8::Object> Object = Value.As<v8::Object>();\
	FJsObject JsValue = FJsObject(JsObject.GetContext(), Object);\
	Arguments._##Name = WidgetAttribute2::MakeAttribute<Type>(JsValue);

#define SET_SLATE_ARUMENT(Name, Type)\
	v8::Local<v8::Value> Value;\
	if (!JsObject.Has(VariableName, Value)) return;\
	if (puerts::converter::Converter<ETextFlowDirection>::accept(JsObject.GetContext(), Value))\
		Arguments._TextFlowDirection = puerts::converter::Converter<ETextFlowDirection>::toCpp(JsObject.GetContext(), Value);\

	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(Text, FText);
	}
	template<typename TArgumentType>
	void Set_TextStyle(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//@TODO 
	}
	template<typename TArgumentType>
	void Set_Font(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(Font, FSlateFontInfo);
	}
	template<typename TArgumentType>
	void Set_StrikeBrush(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//SET_ATTRIBUTE(StrikeBrush, FSlateBrush*);
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(ColorAndOpacity, FSlateColor);
	}
	template<typename TArgumentType>
	void Set_ShadowOffset(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(ShadowOffset, FVector2D);
	}
	template<typename TArgumentType>
	void Set_ShadowColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(ShadowColorAndOpacity, FLinearColor);
	}
	template<typename TArgumentType>
	void Set_HighlightColor(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(HighlightColor, FLinearColor);
	}
	template<typename TArgumentType>
	void Set_HighlightShape(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//@TODO
	}
	template<typename TArgumentType>
	void Set_HighlightText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(HighlightText, FText);
	}
	template<typename TArgumentType>
	void Set_WrapTextAt(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(WrapTextAt, float);
	}
	template<typename TArgumentType>
	void Set_AutoWrapText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(AutoWrapText, bool);
	}
	template<typename TArgumentType>
	void Set_WrappingPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(WrappingPolicy, ETextWrappingPolicy);
	}
	template<typename TArgumentType>
	void Set_TransformPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(TransformPolicy, ETextTransformPolicy);
	}
	template<typename TArgumentType>
	void Set_Margin(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(Margin, FMargin);
	}
	template<typename TArgumentType>
	void Set_LineHeightPercentage(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(LineHeightPercentage, float);
	}
	template<typename TArgumentType>
	void Set_Justification(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(Justification, ETextJustify::Type);
	}
	template<typename TArgumentType>
	void Set_MinDesiredWidth(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_ATTRIBUTE(MinDesiredWidth, float);
	}
	template<typename TArgumentType>
	void Set_TextShapingMethod(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_SLATE_ARUMENT(TextShapingMethod, ETextShapingMethod);
	}
	template<typename TArgumentType>
	void Set_TextFlowDirection(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_SLATE_ARUMENT(TextFlowDirection, ETextFlowDirection);
	}
	template<typename TArgumentType>
	void Set_LineBreakPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//v8::Local<v8::Value> Value;
		//if (!JsObject.Has(VariableName, Value)) return;

		//if (puerts::converter::Converter<IBreakIterator>::accept(JsObject.GetContext(), Value))
		//{
		//	Arguments._LineBreakPolicy = puerts::converter::Converter<IBreakIterator>::toCpp(JsObject.GetContext(), Value);
		//}
	}
	template<typename TArgumentType>
	void Set_OverflowPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_SLATE_ARUMENT(OverflowPolicy, ETextOverflowPolicy);
	}
	template<typename TArgumentType>
	void Set_SimpleTextMode(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		SET_SLATE_ARUMENT(SimpleTextMode, bool);
	}
	template<typename TArgumentType>
	void Set_OnDoubleClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}



	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

};


namespace WidgetArgument3
{
#define SET_SLATE_ATTRIBUTE(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Value> Value; \
		if (!JsObject.Has(VariableName, Value)) return; \
		v8::Local<v8::Object> Object = Value.As<v8::Object>(); \
		FJsObject JsValue = FJsObject(JsObject.GetContext(), Object); \
		Arguments._##Name = WidgetAttribute2::MakeAttribute<Type>(JsValue);\
	}

#define SET_SLATE_ARUMENT(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Value> Value;\
		if (!JsObject.Has(VariableName, Value)) return;\
		if (puerts::converter::Converter<ETextFlowDirection>::accept(JsObject.GetContext(), Value))\
			Arguments._TextFlowDirection = puerts::converter::Converter<ETextFlowDirection>::toCpp(JsObject.GetContext(), Value);\
	}

	/** ======================= SLATE_ATTRIBUTE ======================= **/
	SET_SLATE_ATTRIBUTE(Text, FText);
	template<typename TArgumentType> void Set_TextStyle(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//@TODO 
	}
	SET_SLATE_ATTRIBUTE(Font, FSlateFontInfo);
	template<typename TArgumentType> void Set_StrikeBrush(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//SET_ATTRIBUTE(StrikeBrush, FSlateBrush*);
	}
	SET_SLATE_ATTRIBUTE(ColorAndOpacity, FSlateColor);
	SET_SLATE_ATTRIBUTE(ShadowOffset, FVector2D);
	SET_SLATE_ATTRIBUTE(ShadowColorAndOpacity, FLinearColor);
	SET_SLATE_ATTRIBUTE(HighlightColor, FLinearColor);
	template<typename TArgumentType> void Set_HighlightShape(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//@TODO
	}
	SET_SLATE_ATTRIBUTE(HighlightText, FText);
	SET_SLATE_ATTRIBUTE(WrapTextAt, float);
	SET_SLATE_ATTRIBUTE(AutoWrapText, bool);
	SET_SLATE_ATTRIBUTE(WrappingPolicy, ETextWrappingPolicy);
	SET_SLATE_ATTRIBUTE(TransformPolicy, ETextTransformPolicy);
	SET_SLATE_ATTRIBUTE(Margin, FMargin);
	SET_SLATE_ATTRIBUTE(LineHeightPercentage, float);
	SET_SLATE_ATTRIBUTE(Justification, ETextJustify::Type);
	SET_SLATE_ATTRIBUTE(MinDesiredWidth, float);

	/** ======================= SLATE_ARGUMENT ======================= **/
	SET_SLATE_ARUMENT(TextShapingMethod, ETextShapingMethod);
	SET_SLATE_ARUMENT(TextFlowDirection, ETextFlowDirection);
	template<typename TArgumentType> void Set_LineBreakPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		//v8::Local<v8::Value> Value;
		//if (!JsObject.Has(VariableName, Value)) return;

		//if (puerts::converter::Converter<IBreakIterator>::accept(JsObject.GetContext(), Value))
		//{
		//	Arguments._LineBreakPolicy = puerts::converter::Converter<IBreakIterator>::toCpp(JsObject.GetContext(), Value);
		//}
	}
	SET_SLATE_ARUMENT(OverflowPolicy, ETextOverflowPolicy);
	SET_SLATE_ARUMENT(SimpleTextMode, bool);

	/** ======================= SLATE_EVENT ======================= **/
	template<typename TArgumentType>
	void Set_OnDoubleClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;
		if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			Arguments._OnDoubleClicked.BindLambda([Function](const FGeometry& Geometry, const FPointerEvent& PointerEvent)
				{
					return *Function.Func<FReply*>(Geometry, PointerEvent);
				});
		}
	}



	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

};

namespace WidgetAttribute2
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(FJsObject& JsObject) { return TAttribute<TType>(); }

	/** ======================= MakeAttribute ======================= **/
#define MAKE_ATTRIBUTE(Type)\
	template<> TAttribute<Type> MakeAttribute(FJsObject& JsObject)\
	{\
		v8::Local<v8::Object> Value = JsObject.GetJsObject();\
		if (Value->IsFunction())\
		{\
			TAttribute<Type>::FGetter Getter;\
			Getter.BindLambda([JsObject]() { return JsObject.Func<Type>(); });\
			return TAttribute<Type>::Create(Getter);\
		}\
		if (puerts::converter::Converter<Type>::accept(JsObject.GetContext(), Value))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(JsObject.GetContext(), Value);\
			return TAttribute<Type>(Ret);\
		}\
		return TAttribute<Type>();\
	}

	MAKE_ATTRIBUTE(FText);
	MAKE_ATTRIBUTE(float);
	MAKE_ATTRIBUTE(bool);
	MAKE_ATTRIBUTE(FSlateFontInfo);
	MAKE_ATTRIBUTE(FSlateBrush*);
	MAKE_ATTRIBUTE(FSlateColor);
	MAKE_ATTRIBUTE(FVector2D);
	MAKE_ATTRIBUTE(FLinearColor);
	MAKE_ATTRIBUTE(ETextWrappingPolicy);
	MAKE_ATTRIBUTE(ETextTransformPolicy);
	MAKE_ATTRIBUTE(FMargin);
	MAKE_ATTRIBUTE(ETextJustify::Type);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);
	//MAKE_ATTRIBUTE(bool);


	//template<> TAttribute<FText> MakeAttribute(FJsObject& JsObject) {
	//	v8::Local<v8::Object> Value = JsObject.GetJsObject();
	//	if (Value->IsFunction()) {
	//		TAttribute<FText>::FGetter Getter;
	//		Getter.BindLambda([JsObject]() { return JsObject.Func<FText>(); });
	//		return TAttribute<FText>::Create(Getter);
	//	}
	//	if (puerts::converter::Converter<FText>::accept(JsObject.GetContext(), Value))
	//	{
	//		FText Ret = puerts::converter::Converter<FText>::toCpp(JsObject.GetContext(), Value);
	//		return TAttribute<FText>(Ret);
	//	}
	//	return TAttribute<FText>();
	//};
	//template<> TAttribute<float> MakeAttribute(FJsObject& JsObject) {
	//	v8::Local<v8::Object> Value = JsObject.GetJsObject(); if (Value->IsFunction()) {
	//		TAttribute<float>::FGetter Getter; Getter.BindLambda([JsObject]() { return JsObject.Func<float>(); }); return TAttribute<float>::Create(Getter);
	//	}
	//	else if (Value->IsObject()) {
	//		float Ret = puerts::converter::Converter<float>::toCpp(JsObject.GetContext(), Value); return TAttribute<float>(Ret);
	//	} return TAttribute<float>();
	//};
	//template<> TAttribute<bool> MakeAttribute(FJsObject& JsObject) {
	//	v8::Local<v8::Object> Value = JsObject.GetJsObject(); if (Value->IsFunction()) {
	//		TAttribute<bool>::FGetter Getter; Getter.BindLambda([JsObject]() { return JsObject.Func<bool>(); }); return TAttribute<bool>::Create(Getter);
	//	}
	//	else if (Value->IsObject()) {
	//		bool Ret = puerts::converter::Converter<bool>::toCpp(JsObject.GetContext(), Value); return TAttribute<bool>(Ret);
	//	} return TAttribute<bool>();
	//};

	template<typename TType>
	TOptional<TType> MakeOptional(FJsObject& JsObject) { return TAttribute<TType>(); }
	template<> TOptional<FSlateSound> MakeOptional(FJsObject& JsObject)
	{
		return TOptional<FSlateSound>();
	}

	FSimpleDelegate MakeSimpleDelegate(FJsObject& JsObject)
	{
		return FSimpleDelegate();
	}

	FOnClicked MakeOnClicked(FJsObject& JsObject)
	{
		return FOnClicked();
	}
}

namespace WidgetAttribute1
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(FJsObject& JsObject) { return TAttribute<TType>(); }

	/** ======================= MakeAttribute ======================= **/
	template<> TAttribute<FText> MakeAttribute(FJsObject& JsObject)
	{
		v8::Local<v8::Object> Value = JsObject.GetJsObject();
		if (Value->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), Value);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (Value->IsFunction())
		{
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}
		return TAttribute<FText>();
	}
	template<> TAttribute<float> MakeAttribute(FJsObject& JsObject)
	{
		v8::Local<v8::Object> Value = JsObject.GetJsObject();
		if (Value->IsNumber())
		{
			v8::Maybe<double> v = Value->NumberValue(JsObject.GetContext());
			return TAttribute<float>(v.ToChecked());
		}
		else if (Value->IsFunction())
		{
			TAttribute<float>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					return JsObject.Func<float>();
				});
			return TAttribute<float>::Create(Getter);
		}
		return TAttribute<float>();
	}
	template<> TAttribute<bool> MakeAttribute(FJsObject& JsObject)
	{
		v8::Local<v8::Object> Value = JsObject.GetJsObject();
		if (Value->IsBoolean())
		{
			bool v = Value->BooleanValue(JsObject.GetIsolate());
			return TAttribute<bool>(v);
		}
		else if (Value->IsFunction())
		{
			TAttribute<bool>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					return JsObject.Func<bool>();
				});
			return TAttribute<bool>::Create(Getter);
		}
		return TAttribute<bool>();
	}
	template<> TAttribute<FVector2D> MakeAttribute(FJsObject& JsObject)
	{
		v8::Local<v8::Object> Value = JsObject.GetJsObject();
		if (Value->IsFunction())
		{
			TAttribute<FVector2D>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					return JsObject.Func<FVector2D>();
				});
			return TAttribute<FVector2D>::Create(Getter);
		}
		else if (Value->IsObject())
		{
			double X = JsObject.Get<double>("X");
			double Y = JsObject.Get<double>("Y");
			return TAttribute<FVector2D>(FVector2D(X, Y));
		}
		return TAttribute<FVector2D>();
	}
	//template<> TAttribute<FSlateColor> MakeAttribute(FJsObject& JsObject)
	//{
	//	v8::Local<v8::Object> Value = JsObject.GetJsObject();
	//	if (Value->IsString())
	//	{
	//		std::string TextString = *v8::String::Utf8Value(JsObject.GetIsolate(), Value);
	//		FColor Color = StringConverter::Converter<FColor>(TextString);
	//		return TAttribute<FSlateColor>(Color);
	//	}
	//	if (Value->IsFunction())
	//	{
	//		TAttribute<FSlateColor>::FGetter Getter;
	//		Getter.BindLambda([JsObject]()
	//			{
	//				FSlateColor ColorRet = JsObject.Func_CallBack<FSlateColor>([](v8::Local<v8::Context> Context, v8::Local<v8::Value> MaybeRet)
	//					{
	//						if (MaybeRet->IsString())
	//						{
	//							std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet);
	//							FColor Color = StringConverter::Converter<FColor>(std_str);
	//							return FSlateColor(Color);
	//						}
	//						if (MaybeRet->IsObject())
	//						{
	//							// @TODO 判断对象类型，是否是FLinearColor实例
	//							FLinearColor LinearColor = puerts::converter::Converter<FLinearColor>::toCpp(Context, MaybeRet);
	//							return FSlateColor(LinearColor);
	//
	//							// 如果不是则从{ R: number, G: number, B:number, A: number }取值
	//						}
	//						return FSlateColor();
	//					});
	//				return ColorRet;
	//			});
	//		return TAttribute<FSlateColor>::Create(Getter);
	//	}
	//	else if (Value->IsObject())
	//	{
	//		double R, G, B, A;
	//		v8::Local<v8::Value> RV;
	//
	//		if (JsObject.Has("R", RV)) R = JsObject.Get<double>("R");
	//		if (JsObject.Has("G", RV)) G = JsObject.Get<double>("G");
	//		if (JsObject.Has("B", RV)) B = JsObject.Get<double>("B");
	//		if (JsObject.Has("A", RV)) A = JsObject.Get<double>("A");
	//
	//		return TAttribute<FSlateColor>(FLinearColor(R, G, B, A));
	//	}
	//	return TAttribute<FSlateColor>();
	//}
	template<> TAttribute<FSlateBrush> MakeAttribute(FJsObject& JsObject)
	{
		v8::Local<v8::Object> Value = JsObject.GetJsObject();
		if (Value->IsFunction())
		{
			TAttribute<FSlateBrush>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					return JsObject.Func<FSlateBrush>();
				});
			return TAttribute<FSlateBrush>::Create(Getter);
		}
		else if (Value->IsObject())
		{
			FSlateBrush Ret = puerts::converter::Converter<FSlateBrush>::toCpp(JsObject.GetContext(), Value);
			return TAttribute<FSlateBrush>(Ret);
		}
		return TAttribute<FSlateBrush>();
	}

#define MAKE_ATTRIBUTE(Type)\
	template<> TAttribute<Type> MakeAttribute(FJsObject& JsObject)\
	{\
		v8::Local<v8::Object> Value = JsObject.GetJsObject();\
		if (Value->IsFunction())\
		{\
			TAttribute<Type>::FGetter Getter;\
			Getter.BindLambda([JsObject]()\
				{\
					return JsObject.Func<Type>();\
				});\
			return TAttribute<Type>::Create(Getter);\
		}\
		else if (Value->IsObject())\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(JsObject.GetContext(), Value);\
			return TAttribute<Type>(Ret);\
		}\
		return TAttribute<Type>();\
	}

	MAKE_ATTRIBUTE(FSlateColor);
	MAKE_ATTRIBUTE(FMargin);
}

namespace WidgetAttribute
{
	template<typename TType>
	TAttribute<TType> MakeAttribute_4(FJsObject& JsObject, v8::Local<v8::Value> Value) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute_4(FJsObject& InJsObject, v8::Local<v8::Value> InValue)
	{
		v8::Local<v8::Object> JsValue1 = InJsObject.GetJsObject();
		v8::Local<v8::String> Type1 = JsValue1->TypeOf(InJsObject.GetIsolate());
		FString TypeString1 = puerts::FV8Utils::ToFString(InJsObject.GetIsolate(), Type1);

		FJsObject JsObject = InJsObject;
		v8::Local<v8::Object> JsValue = InValue.As<v8::Object>();
		if (InValue->IsUndefined())
		{
			v8::Local<v8::Object> Object = InValue.As<v8::Object>();
			JsObject = FJsObject(InJsObject.GetContext(), Object);
			JsValue = JsObject.GetJsObject();
		}

		v8::Local<v8::String> Type = JsValue->TypeOf(InJsObject.GetIsolate());
		FString TypeString = puerts::FV8Utils::ToFString(InJsObject.GetIsolate(), Type);

		if (JsValue->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), JsValue);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (JsValue->IsFunction())
		{
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([&JsObject]()
				{
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}
		return TAttribute<FText>();
	}


	template<typename TType>
	TAttribute<TType> MakeAttribute1(v8::Isolate* Isolate, v8::Local<v8::Context> Context, v8::Local<v8::Value> Value) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute1(v8::Isolate* Isolate, v8::Local<v8::Context> Context, v8::Local<v8::Value> Value)
	{
		if (Value->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(Isolate, Value);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (Value->IsFunction())
		{
			v8::Local<v8::Function> Function = Value.As<v8::Function>();
			FJsObject JsObject = FJsObject(Context, Function);
			std::string Ret = JsObject.Func<std::string>();

			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function, &Context, Isolate]()
				{
					v8::MaybeLocal<v8::Value> MaybeRet = Function->Call(Context, v8::Undefined(Isolate), 0, nullptr);
					std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet.ToLocalChecked());
					FString String = UTF8_TO_TCHAR(std_str.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);

			Getter.BindLambda([Value, &Context]()
				{
					v8::Local<v8::Function> Function = Value.As<v8::Function>();
					FJsObject JsObject = FJsObject(Context, Function);
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);

			//v8::Local<v8::Context> Context = Isolate->GetIncumbentContext();
			//v8::Local<v8::Function> Function = Value.As<v8::Function>();
			//TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function, Context, Isolate]()
				{
					v8::Isolate::Scope IsolateScope(Isolate);
					v8::HandleScope HandleScope(Isolate);
					//auto Context = GContext.Get(Isolate);
					v8::Context::Scope ContextScope(Context);

					v8::MaybeLocal<v8::Value> MaybeRet = Function->Call(Context, v8::Undefined(Isolate), 0, nullptr);
					std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet.ToLocalChecked());
					FString String = UTF8_TO_TCHAR(std_str.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}

		return TAttribute<FText>();
	}


	template<typename TType>
	TAttribute<TType> MakeAttribute0(FJsObject JsObject) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute0(FJsObject JsObject)
	{
		return MakeAttribute1<FText>(JsObject.GetIsolate(), JsObject.GetContext(), JsObject.GetJsObject());
	}

	template<typename TType>
	TAttribute<TType> MakeAttribute(FJsObject JsObject) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute(FJsObject JsObject)
	{
		if (JsObject.GetJsObject()->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), JsObject.GetJsObject());
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (JsObject.GetJsObject()->IsFunction())
		{
			auto Function = JsObject;
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}

		return TAttribute<FText>();
	}
};
