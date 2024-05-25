#include "GlueCode/SlateCoreGlue.h"

struct AutoRegisterSlateCoreGlue
{
	AutoRegisterSlateCoreGlue()
	{
		puerts::DefineClass<FReply>()
			//.Function("Handled", MakeFunction(&FReply::Handled))
			//.Function("Unhandled", MakeFunction(&FReply::Unhandled))
			.Register();

		puerts::DefineClass<FSlateWidgetClassData>()
			.Method("GetWidgetType", MakeFunction(&FSlateWidgetClassData::GetWidgetType))
			.Register();

		puerts::DefineClass<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&FSlateControlledConstruction::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&FSlateControlledConstruction::GetWidgetClass))
			.Register();

		puerts::DefineClass<SWidget>()
			.Extends<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&SWidget::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&SWidget::GetWidgetClass))
			.Register();
		RegisterTSharedPtr(SWidget);
		RegisterTSharedRef(SWidget);

		puerts::DefineClass<SCompoundWidget>()
			.Extends<SWidget>()
			.Register();
		RegisterTSharedPtr(SCompoundWidget);
		RegisterTSharedRef(SCompoundWidget);

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();
		RegisterTSharedPtr(SLeafWidget);
		RegisterTSharedRef(SLeafWidget);
	}
};

AutoRegisterSlateCoreGlue __AutoRegisterSlateCoreGlue__;
