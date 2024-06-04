// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Binding.hpp"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"

namespace puerts
{
#define DefineUEType(Type)\
	template <> struct ScriptTypeName<Type> { static constexpr auto value() { return Literal("UE.") + Literal(#Type).Sub<1>(); }};
#define DefineUEType_Enum(Type)\
	template <> struct ScriptTypeName<Type> { static constexpr auto value() { return Literal("UE.") + Literal(#Type); }};
#define DefineUEType_Enum_Type(Type)\
	template <> struct ScriptTypeName<Type> { static constexpr auto value() { return Literal("UE.") + Literal(#Type).Sub<1, 5>(); }};

	DefineUEType(FMargin);
	DefineUEType(FTextBlockStyle);
	DefineUEType(FButtonStyle);
	DefineUEType(FComboButtonStyle);
	DefineUEType(FSlateFontInfo);
	DefineUEType(FSlateBrush);
	DefineUEType(FLinearColor);
	DefineUEType(FSlateColor);
	DefineUEType(FVector2D);
	DefineUEType(FCheckBoxStyle);
	DefineUEType(TOptional<FSlateSound>);
	DefineUEType(TOptional<ETextShapingMethod>);
	DefineUEType(TOptional<ETextFlowDirection>);
	DefineUEType(TOptional<ESlateCheckBoxType::Type>);
	DefineUEType(TOptional<EMouseCursor::Type>);
	DefineUEType(TOptional<EPopupMethod>);
	DefineUEType(FExpandableAreaStyle);

	DefineUEType_Enum(ETextWrappingPolicy);
	DefineUEType_Enum(ETextTransformPolicy);
	DefineUEType_Enum(ETextShapingMethod);
	DefineUEType_Enum(ETextFlowDirection);

	template <> struct ScriptTypeName<ETextJustify::Type> { static constexpr auto value() { return Literal("UE.") + Literal("ETextJustify"); } };
}