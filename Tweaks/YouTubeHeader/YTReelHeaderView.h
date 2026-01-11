#import <UIKit/UIKit.h>
#import "YTResponder.h"
#import "YTReelHeaderDelegate.h"
#import "YTReelTransparentStackView.h"

@interface YTReelHeaderView : UIView <YTResponder>
@property (nonatomic, strong) id<YTReelHeaderDelegate> delegate;
@property (nonatomic, strong) YTReelTransparentStackView *leftStackView;
@property (nonatomic, strong) YTReelTransparentStackView *rightStackView;
- (void)addLeftStackView:(id)view toView:(id)view;
- (void)addRightStackView:(id)view toView:(id)view;
- (id<YTReelHeaderDelegate>)delegate;
- (void)setDelegate:(id<YTReelHeaderDelegate>)delegate;
- (void)didPressVideoQuality:(id)arg;
- (YTQTMButton *)buttonWithImage:(UIImage *)image accessibilityLabel:(NSString *)accessibilityLabel verticalContentPadding:(CGFloat)verticalContentPadding;
@end
