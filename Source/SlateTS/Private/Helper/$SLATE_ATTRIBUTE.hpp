#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "WidgetAttribute.hpp"

#define $SLATE_ATTRIBUTE(Type, Name, Tag)\
$SLATE_ATTRIBUTE$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SET_SLATE_ATTRIBUTE ======================= **/
namespace $SLATE_ATTRIBUTE$
{
#define DEFINE_FUNCTION_SLATE_ATTRIBUTE(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		Arguments._##Name = WidgetAttribute::MakeAttribute<Type>(Context, JsValue);\
	}
	
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, IsChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, ToggleChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, TogglePitchChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, ToggleRollChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, ToggleYawChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EColorBlockAlphaDisplayMode, AlphaDisplayMode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EColumnSortMode::Type, InitialSortMode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EColumnSortMode::Type, SortMode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EColumnSortPriority::Type, SortPriority, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EHorizontalAlignment, HAlign, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EKeyboardType, KeyboardType, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EKeyboardType, VirtualKeyboardType, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EListItemAlignment, ItemAlignment, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EMenuPlacement, MenuPlacement, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EMenuPlacement, Placement, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EOrientation, Orientation, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ESelectionMode::Type, SelectionMode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EStretch::Type, Stretch, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EStretchDirection::Type, StretchDirection, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextTransformPolicy, TransformPolicy, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextWrappingPolicy, WrappingPolicy, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EVirtualKeyboardDismissAction, VirtualKeyboardDismissAction, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EVirtualKeyboardTrigger, VirtualKeyboardTrigger, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EVisibility, ScrollbarVisibility, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FFrameRate, Value, FFrameRate);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FInputChord, SelectedKey, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, Color, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, ColorAndOpacity, FLinearColor);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, EndColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, HighlightColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, IconColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, SelectedColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, ShadowColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, StartColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, TabColorScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, TargetColorAttribute, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, AreaTitlePadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, ButtonContentPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, ContentPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, HScrollBarPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, HeaderPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, Margin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, OverrideTextMargin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, Padding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, SlotPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, TextMargin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, UniformPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, VScrollBarPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, HeightOverride, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxAspectRatio, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinAspectRatio, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredWidth, FOptionalSize);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, WidthOverride, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSceneViewport*, SceneViewport, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, BackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, BodyBorderBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, BorderBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ButtonColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, CenterBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ColorAndOpacity, FSlateColor);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, FillColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, FocusedForegroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, IconColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, LabelColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ReadOnlyForegroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, SliderBarColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, SliderHandleColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, SliderProgressColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, TimecodeColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, AreaTitleFont, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, LabelFont, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, TimecodeFont, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateIcon, Icon, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, AddButtonToolTip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, AreaTitle, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, CollapsedText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, DefaultLabel, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, DefaultTooltip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, ExpandedText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, HighlightText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, HintText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, InitialText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, Label, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, LabelSuffix, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, LabelText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, Name, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, NotRecommendedText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, NotRecommendedToolTip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, OptionText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, RecommendedText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, RemoveButtonToolTip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, RenameButtonToolTip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, SearchText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, Text, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, Title, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FTimecode, Timecode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, BorderFadeDistance, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, BorderPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, ContentScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, DesiredSizeScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, MinDesiredSlotSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, RenderScaleOrigin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, ShadowOffset, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, Size, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, Thickness, FVector2D);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, ViewportSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, VisualOffset, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector4, CornerRadius, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(NumericType, Delta, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(NumericType, SliderExponentNeutralValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(NumericType, SpinDelta, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(NumericType, Value, NumericType);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(OptionType, Value, OptionType);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TArray<FColor*>, TargetFColors, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TArray<FColorChannels>, TargetColorChannels, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TArray<FLinearColor*>, TargetLinearColors, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TArray<FLinearColor>, GradientColors, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TArray<OptionType>, Values, );

	/** TOptional<> **/
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, MaxSliderValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, MaxValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, MinSliderValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, MinValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, WheelStep, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<int32>, MaxFractionalDigits, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<int32>, MinFractionalDigits, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<EMouseCursor::Type>, HeaderCursor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<SSearchBox::FSearchResultData>, SearchResultData, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<FVector2D>, DesiredSizeOverride, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, Pitch, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, Roll, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, Value, TOptional_NumericType);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<NumericType>, Yaw, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<VectorType>, MaxSliderVector, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<VectorType>, MaxVector, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<VectorType>, MinSliderVector, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<VectorType>, MinVector, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<VectorType>, Vector, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<float>, Percent, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<int32>, BlurRadius, );
	/** TOptional<> **/

	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TSharedPtr< IToolTip >, ToolTip, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TSharedPtr<SDockingTabStack>, ParentStackNode, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TSharedPtr<SWidget>, OptionalOwningDetailsView, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TSharedPtr<SWindow>, ParentWindow, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AllowContextMenu, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AllowMultiLine, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AllowSpin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AlwaysUsesDeltaSnap, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AutoWrapText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, CanShow, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ClearKeyboardFocusOnCommit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ClearTextSelectionOnFocusLoss, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ColorIsHSV, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, DelayChangeNotificationsWhileTyping, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, DisplayLabel, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, EnableSlider, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, EvenRowDistribution, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, HasAlphaBackground, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, HasMultipleValues, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IgnoreClipping, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IgnoreInheritedScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IndentHandle, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsCaretMovedWhenGainFocus, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsExpanded, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsFocusable, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsInteractive, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsPassword, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsReadOnly, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, IsSearching, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, Locked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, Muted, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, OnlyRefreshOnMouseUp, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, OnlyRefreshOnOk, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, RevertTextOnEscape, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, SelectAllTextOnCommit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, SelectAllTextWhenFocused, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, SelectWordOnMouseDoubleClick, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShouldDrawWires, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShouldGenerateWidget, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShouldStackHierarchyHeaders, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShowBackgroundForAlpha, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShowEffectWhenDisabled, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShowLeadingDelimiter, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, SupportDynamicSliderMaxValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, SupportDynamicSliderMinValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, UseAlpha, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, UseSRGB, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, UsesSmallIcon, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, bShowNamedValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, bUseCustomDefaultValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, AlphaBackgroundBrush, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, BackgroundImageComposing, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, BackgroundImageSelected, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, BorderImage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, CaretImage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, DelimiterImage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, HighlightShape, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, Image, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, StrikeBrush, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, BlurStrength, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, CurrentSlideAmount, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, CustomDefaultValue, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, DPIScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, DelayChangeNotificationsWhileTypingSeconds, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, DisplayGamma, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, ExponentDisplacement, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, FadeRate, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, FillWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, IndentAmount, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, ItemHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, ItemWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, LayoutScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, LineHeightPercentage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, ManualWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MaxDesiredSlotHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MaxDesiredSlotWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MaxUniformSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MaxWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinDesiredSlotHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinDesiredSlotWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinDesiredValueWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinDesiredWidth, float);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinUniformSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MoveSpeed, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, PeakValueLeftLimit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, PeakValueRightLimit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, PreferredSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, PreferredWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, RenderScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, SlideValueLeftLimit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, SlideValueRightLimit, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, SliderExponent, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, StepSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, SuggestionListMaxHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, Thickness, float);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, UserSpecifiedScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, Value, float);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, Volume, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, WrapTextAt, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, BaseIndentLevel, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, CurrentItemIndex, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, DesiredWheelSize, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, HighlightedHandleIndex, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, LinearDeltaSensitivity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, MaxPinnedItems, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, NumDesiredItems, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, ShiftMouseMovePixelPerDelta, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(int32, WidgetIndex, )
}
