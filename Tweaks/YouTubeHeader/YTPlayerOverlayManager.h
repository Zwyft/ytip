#import "YTVarispeedSwitchController.h"
#import "YTVideoPlayerOverlayDelegate.h"

@interface YTPlayerOverlayManager : NSObject <YTVideoPlayerOverlayDelegate>
@property (nonatomic, assign) float currentPlaybackRate;
@property (nonatomic, strong, readonly) YTVarispeedSwitchController *varispeedController;
- (void)varispeedSwitchController:(YTVarispeedSwitchController *)varispeed didSelectRate:(float)rate;
- (void)setCurrentPlaybackRate:(float)rate;
- (void)setPlaybackRate:(float)rate;
- (void)didPressToggleFullscreen;
@end
