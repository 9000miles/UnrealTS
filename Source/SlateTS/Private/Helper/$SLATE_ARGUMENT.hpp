#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "SlateCoreGlue.hpp"
#include "Widgets/Notifications/SErrorText.h"

#define $SLATE_ARGUMENT(Type, Name, Tag)\
$SLATE_ARGUMENT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SLATE_ARGUMENT ======================= **/
namespace $SLATE_ARGUMENT$
{
#define DEFINE_FUNCTION_SLATE_ARGUMENT(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (puerts::converter::Converter<Type>::accept(Context, JsValue))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(Context, JsValue);\
			Arguments._##Name = Ret;\
		}\
	}

	DEFINE_FUNCTION_SLATE_ARGUMENT(EAllowOverscroll, AllowOverscroll, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(SThrobber::EAnimation, Animate, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EAutoCenter, AutoCenter, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EButtonClickMethod::Type, ClickMethod, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EButtonPressMethod::Type, PressMethod, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EButtonTouchMethod::Type, TouchMethod, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EColorGradingModes, ColorGradingModes, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EConsumeMouseWheel, ConsumeMouseWheel, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EDescendantScrollDestination, NavigationDestination, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EFocusCause, DragFocusCause, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EFocusCause, ScrollBarDragFocusCause, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EFocusCause, ScrollbarDragFocusCause, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EHeaderComboVisibility, HeaderComboVisibility, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EHorizontalAlignment, HAlign, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EHorizontalAlignment, HAlignCell, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EHorizontalAlignment, HAlignHeader, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ELabelLocation, LabelLocation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EModifierKey::Type, ModiferKeyForNewLine, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EOrientation, ListOrientation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EOrientation, Orientation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EProgressBarFillStyle::Type, BarFillStyle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EProgressBarFillType::Type, BarFillType, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EScrollWhenFocusChanges, ScrollWhenFocusChanges, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ESidebarLocation, Location, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ESizingRule, SizingRule, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ESplitterResizeMode::Type, ResizeMode, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ETabRole, TabRole, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ETableRowSignalSelectionMode, SignalSelectionMode, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVerticalAlignment, LabelVAlign, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVerticalAlignment, VAlign, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVerticalAlignment, VAlignCell, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVerticalAlignment, VAlignHeader, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVisibility, IsRenameVisible, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVisibility, ScrollBarVisibility, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EWindowActivationPolicy, ActivationPolicy, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EWindowType, Type, EWindowType);
	DEFINE_FUNCTION_SLATE_ARGUMENT(FColor, BackgroundColor, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, LabelPadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, LayoutBorder, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, Padding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, SafeAreaScale, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, ScrollBarPadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, TogglePadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, UserResizeBorder, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FName, ColumnId, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FName, StatId, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FName, StyleName, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FName, TutorialHighlightName, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FOnConstrainVector, ConstrainVector, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FOnGetContent, OnWrapButtonClicked, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FPropertyPath, Path, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FRuntimeFloatCurve, SliderRange, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateBrush, CenterBackgroundBrush, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateColor, BorderBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateColor, BorderForegroundColor, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FString, DebugName, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FString, InitialURL, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, DefaultText, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, ErrorText, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, KeySelectionText, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, Label, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, NoKeySpecifiedText, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, UndeterminedString, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, ClientSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, HandStartEndRatio, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, InnerSlotPadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, ScreenPosition, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, ScrollBarThickness, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, ShadowOffset, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, Size, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVirtualKeyboardOptions, VirtualKeyboardOptions, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FWindowTransparency, SupportsTransparency, FWindowTransparency);
	DEFINE_FUNCTION_SLATE_ARGUMENT(INotifyHook*, NotifyHook, );
	//DEFINE_FUNCTION_SLATE_ARGUMENT(OptionType, InitiallySelectedItem, );
	//DEFINE_FUNCTION_SLATE_ARGUMENT(OptionType, Option, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(SDockingNode::RelativeDirection, DockDirection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray< TSharedPtr<FString> >*, OptionsSource, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray< TSharedRef< class ITextDecorator > >, Decorators, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<FCommonFrameRateInfo>, PresetValues, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<FKey>, EscapeKeys, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<FNamedValue>, DropDownValues, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<FString>, AltRetryDomains, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<FString>, TextOptions, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TArray<float>, ValueTags, );

	/** TOptional<> **/
	DEFINE_FUNCTION_SLATE_ARGUMENT(FMargin, HeaderContentPadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, FillSized, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, FixedWidth, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EPopupMethod, Method, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EPopupMethod, PopupMenuMethod, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ESlateCheckBoxType::Type , Type, ESlateCheckBoxType);
	DEFINE_FUNCTION_SLATE_ARGUMENT(ETextFlowDirection, TextFlowDirection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ETextOverflowPolicy, OverflowPolicy, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(ETextShapingMethod, TextShapingMethod, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(EVisibility, LabelVisibility, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FBrowserContextSettings, ContextSettings, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateSound, CheckedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateSound, HoveredSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateSound, PressedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FSlateSound, UncheckedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FString, ContentsToLoad, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FText, OverrideDisplayName, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(FVector2D, OverrideScreenSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, sRGBOverride, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FieldColorSettings > , OverrideColorSettings, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(double, FixedLineScrollOffset, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, InactiveTextAlpha, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxHeight, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxWidth, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinHeight, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinWidth, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, OverrideDpiScale, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, SliderValueMax, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, SliderValueMin, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, ValueMax, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, ValueMin, );
	/** TOptional<> **/

	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr< INumericTypeInterface<NumericType> >, TypeInterface, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr< ITextLayoutMarshaller >, Marshaller, TSharedPtr_ITextLayoutMarshaller);
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr< SScrollBar >, HScrollBar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr< SScrollBar >, VScrollBar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr< class IRichTextMarkupParser >, Parser, );
	//DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<FAndroidWebBrowserWindow>, WebBrowserWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<FString>, InitiallySelectedItem, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<IBreakIterator>, LineBreakPolicy, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<ISlateViewport>, ViewportInterface, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SDockingNode>, InitialContent, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SHeaderRow>, HeaderRow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SMenuAnchor>, MenuAnchor, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SScrollBar>, ExternalScrollbar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<STableViewBase>, OwnerTableView, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SWidget>, MenuContent, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SWidget>, PossiblyNullContent, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<SWindow>, ParentWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<class FRichTextLayoutMarshaller>, Marshaller, TSharedPtr_FRichTextLayoutMarshaller);
	//DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<class IErrorReportingWidget>, ErrorReporting, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(TSharedPtr<class SDockingNode>, OwnerNode, );
	//DEFINE_FUNCTION_SLATE_ARGUMENT(TWeakObjectPtr<APlayerController>, PCOwner, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(USlateVectorArtData*, MeshData, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AdjustInitialSizeAndPositionForDPIScale, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowAnimatedTransition, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowGamepadKeys, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowInvisibleItemSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowModifierKeys, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowSpin, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AllowWheel, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AlwaysShowScrollbar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AlwaysShowScrollbarTrack, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AlwaysShowScrollbars, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AnimateWheelScrolling, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ApplyWidgetStyleToMenu, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, AutoFocus, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, BackPadScrolling, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, CanEverClose, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, CheckBoxContentUsesAutoWidth, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, CollapseMenuOnParentFocus, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, CreateTitleBar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, DisplayInlineVersion, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, DisplayToggle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EnableAnimatedScrolling, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EnableBlending, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EnableGammaCorrection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EnableStereoRendering, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EnableWheel, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, EscapeCancelsSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ExpandAdvancedSection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, FitInWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, FlipForRightToLeftFlowDirection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, FocusWhenFirstShown, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ForceSmallIcons, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, FrontPadScrolling, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, GameMenu, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HandleDirectionalNavigation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HandleGamepadEvents, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HandleSpacebarSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HasAlphaBackground, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HasCloseButton, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HasDownArrow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HideWhenNotInUse, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, HighlightParentNodesForSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IgnoreTextureAlpha, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, InitiallyCollapsed, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, InterceptLoadRequests, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsCollapsedByParent, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsDocumentArea, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsFocusable, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsInitiallyMaximized, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsInitiallyMinimized, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsPopupWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsTitleSafe, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, IsTopmostWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, MouseUsesStep, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, MultiLine, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, OverrideColorPickerCreation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PadBottom, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PadLeft, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PadRight, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PadTop, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PersistentBreadcrumbs, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PreMultipliedAlpha, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, PreventThrottling, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, RenderDirectlyToWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, RenderOnInvalidation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, RenderOnPhase, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, RenderWithLocalTransform, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, RequiresControllerLock, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ReturnFocusToSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ReverseGammaCorrection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SaneWindowPlacement, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ScrollBarAlwaysVisible, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SelectAllTextWhenFocused, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShouldAutosize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShouldDeferPaintingAfterWindowContent, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShouldManageParentWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShouldPreserveAspectRatio, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowAddressBar, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowControls, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowErrorMessage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowInNewWindow, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowInitialThrobber, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowSliderHand, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowSliderHandle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, ShowWires, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SimpleTextMode, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsEmptySelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsMaximize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsMinimize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsMultiSelection, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsThumbMouseButtonNavigation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, SupportsTransparency, bool);
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseAllottedSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseAllottedWidth, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseApplicationMenuStack, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseOSWindowBorder, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseTransparency, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, UseVerticalDrag, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, WrapHorizontalNavigation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bAllowDragging, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bAllowPreselectedItemActivation, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bApplyAlphaToBlur, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bColorAxisLabels, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bDistributeItemsEvenly, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bDragAnywhere, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bIsMultichoice, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(bool, bManualManageDPI, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, BackgroundHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, BackgroundImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, BackgroundPressedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, BodyBorderImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, CheckedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, CheckedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, CheckedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, FillImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, LowQualityFallbackBrush, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, MarqueeImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, PieceImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, SeparatorImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UncheckedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UncheckedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UncheckedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UndeterminedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UndeterminedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const FSlateBrush*, UndeterminedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const ISlateStyle*, DecoratorStyleSet, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const ISlateStyle*, ExpanderStyleSet, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const ISlateStyle*, StyleSet, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const TArray<ItemType>*, ListItemsSource, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const TArray<ItemType>*, TreeItemsSource, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(const TArray<ItemType>*, WidgetItemsSource, );
	//DEFINE_FUNCTION_SLATE_ARGUMENT(const TArray<OptionType>*, OptionsSource, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, AngleBetweenItems, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, AngularOffset, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, ColumnGutter, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, HitDetectionSplitterHandleSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, InitialOpacity, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MainDelta, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxDrawerSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxHeight, float);
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxListHeight, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MaxValue, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinDrawerSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinValue, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinWidth, float);
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, MinimumSlotHeight, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, NavigationScrollOffset, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, NavigationScrollPadding, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, Period, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, PhysicalSplitterHandleSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, RefreshRate, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, RowGutter, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, SectorCentralAngle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, SliderHandleEndAngle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, SliderHandleStartAngle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, StartingAngle, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, TargetDrawerSize, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, Thickness, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(float, WheelScrollMultiplier, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int, BrowserFrameRate, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, ItemCount, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, MainShiftMouseMovePixelPerDelta, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, MaxSegmentsPerLine, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, NumPieces, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, Phase, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, PhaseCount, );
	DEFINE_FUNCTION_SLATE_ARGUMENT(int32, ShiftMouseMovePixelPerDelta, )
}