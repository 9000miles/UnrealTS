namespace STextBlock {
    class Arguments {
        Text?: string | (() => string)
        TextStyle?: UE.TextBlockStyle
        Font?: UE.SlateFontInfo | (() => UE.SlateFontInfo)
        StrikeBrush?: UE.SlateBrush | (() => UE.SlateBrush)
        ColorAndOpacity?: UE.LinearColor | (() => UE.LinearColor)
        ShadowOffset?: UE.Vector2D | (() => UE.Vector2D)
        ShadowColorAndOpacity?: UE.LinearColor | (() => UE.LinearColor)
        HighlightColor?: UE.LinearColor | (() => UE.LinearColor)
        HighlightShape?: UE.SlateBrush | (() => UE.SlateBrush)
        HighlightText?: string | (() => string)
        WrapTextAt?: number | (() => number)
        AutoWrapText?: boolean | (() => boolean)
        WrappingPolicy?: UE.ETextWrappingPolicy | (() => UE.ETextWrappingPolicy)
        TransformPolicy?: UE.ETextTransformPolicy | (() => UE.ETextTransformPolicy)
        Margin?: UE.Margin | (() => UE.Margin)
        LineHeightPercentage?: number | (() => number)
        Justification?: UE.ETextJustify | (() => UE.ETextJustify)
        MinDesiredWidth?: number | (() => number)
        TextShapingMethod?: UE.ETextShapingMethod
        TextFlowDirection?: UE.ETextFlowDirection
        LineBreakPolicy?: cpp.IBreakIterator
        OverflowPolicy?: UE.ETextOverflowPolicy
        SimpleTextMode?: boolean
        OnDoubleClicked?: () => cpp.FReply
    }
}
class STextBlock extends SLeafWidget {
    static SNew(Arguments: STextBlock.Arguments, Filename: string): UE.TSharedPtr<cpp.STextBlock>;
    static SAssignNew(WidgetRef: $Ref<UE.TSharedPtr<cpp.STextBlock>>, Arguments: STextBlock.Arguments, Filename: string): void;
    static MakeShared(): UE.TSharedPtr<cpp.STextBlock>;
    GetText(): string;
    SetText(Text: string | (() => string)): void;
    SetHighlightText(p0: object): void;
    SetFont(p0: object): void;
    SetColorAndOpacity(p0: object): void;
    SetWrapTextAt(p0: object): void;
    SetAutoWrapText(p0: object): void;
    SetWrappingPolicy(p0: object): void;
    SetTransformPolicy(p0: object): void;
    SetShadowOffset(p0: object): void;
    SetShadowColorAndOpacity(p0: object): void;
    SetHighlightColor(p0: object): void;
    SetMinDesiredWidth(p0: object): void;
    SetLineHeightPercentage(p0: object): void;
    SetMargin(p0: object): void;
    SetJustification(p0: object): void;
}
