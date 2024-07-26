#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"
#include "Widgets/SlateControlledConstruction.h"
#include "Framework/MultiBox/MultiBox.h"
#include "Widgets/SBoxPanel.h"

UsingCppType(FSlateWidgetClassData);

UsingCppType(FSlateControlledConstruction);

#define USING_WIDGET_TYPE(Type)\
UsingCppType(Type);\
UsingTSharedPtr(Type);\
UsingTSharedRef(Type);

UsingCppType(SWidget);
UsingTSharedPtr(SWidget);
UsingTSharedRef(SWidget);

UsingCppType(SCompoundWidget);
UsingTSharedPtr(SCompoundWidget);
UsingTSharedRef(SCompoundWidget);

UsingCppType(SLeafWidget);
UsingTSharedPtr(SLeafWidget);
UsingTSharedRef(SLeafWidget);

UsingCppType(SPanel);
UsingTSharedPtr(SPanel);
UsingTSharedRef(SPanel);

UsingCppType(SMultiBlockBaseWidget);
UsingTSharedPtr(SMultiBlockBaseWidget);
UsingTSharedRef(SMultiBlockBaseWidget);

USING_WIDGET_TYPE(SBoxPanel)

UsingCppType(FReply);
