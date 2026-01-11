TARGET = iphone:clang:16.4:14.0
YTLitePlus_USE_FISHHOOK = 0
ARCHS = arm64
MODULES = jailed
FINALPACKAGE = 1
CODESIGN_IPA = 0
PACKAGE_VERSION = X.X.X-X.X

TWEAK_NAME = YTLitePlus
DISPLAY_NAME = YouTube
BUNDLE_ID = com.google.ios.youtube

EXTRA_CFLAGS := $(addprefix -I,$(shell find Tweaks/FLEX -type d)) -I$(THEOS_PROJECT_DIR)/Tweaks -Wno-vla-cxx-extension -Wno-vla

before-all::
	sed -i '' 's/ios-simulator/ios/g' $(THEOS)/vendor/lib/CydiaSubstrate.framework/CydiaSubstrate.tbd

YTLitePlus_INJECT_DYLIBS = libcolorpicker.dylib .theos/obj/iSponsorBlock.dylib .theos/obj/YouPiP.dylib .theos/obj/YouTubeDislikesReturn.dylib .theos/obj/YTABConfig.dylib .theos/obj/YouMute.dylib .theos/obj/YTHoldForSpeed.dylib .theos/obj/YTLite.dylib .theos/obj/YTVideoOverlay.dylib .theos/obj/YouGroupSettings.dylib .theos/obj/YouQuality.dylib
YTLitePlus_FILES = YTLitePlus.xm $(shell find Source -name '*.xm' -o -name '*.x' -o -name '*.m') $(shell find Tweaks/FLEX -type f \( -iname \*.c -o -iname \*.m -o -iname \*.mm \))
YTLitePlus_IPA = ./tmp/Payload/YouTube.app
YTLitePlus_CFLAGS = -fobjc-arc -Wno-deprecated-declarations -Wno-unsupported-availability-guard -Wno-unused-but-set-variable -DTWEAK_VERSION=$(PACKAGE_VERSION) $(EXTRA_CFLAGS)
YTLitePlus_FRAMEWORKS = UIKit Security

include $(THEOS)/makefiles/common.mk
include $(THEOS_MAKE_PATH)/tweak.mk
SUBPROJECTS += Tweaks/iSponsorBlock Tweaks/YouPiP Tweaks/Return-YouTube-Dislikes Tweaks/YTABConfig Tweaks/YouMute Tweaks/YTLite Tweaks/YTHoldForSpeed Tweaks/YTVideoOverlay Tweaks/YouQuality Tweaks/YouGroupSettings
include $(THEOS_MAKE_PATH)/aggregate.mk

before-package::
	@echo -e "==> \033[1mMoving tweak's bundle to Resources/...\033[0m"
	@echo "Forcing MinimumOSVersion to 14.0..."
	@plutil -replace MinimumOSVersion -string "14.0" $(YTLitePlus_IPA)/Info.plist
	@echo "Alderis framework provided manually."
	@cp -R Tweaks/YTLite/layout/Library/Application\ Support/YTLite.bundle Resources/
	@cp -R Tweaks/YouPiP/layout/Library/Application\ Support/YouPiP.bundle Resources/
	@cp -R Tweaks/Return-YouTube-Dislikes/layout/Library/Application\ Support/RYD.bundle Resources/
	@cp -R Tweaks/YTABConfig/layout/Library/Application\ Support/YTABC.bundle Resources/
	@cp -R Tweaks/YouMute/layout/Library/Application\ Support/YouMute.bundle Resources/
	@cp -R Tweaks/YTHoldForSpeed/layout/Library/Application\ Support/YTHoldForSpeed.bundle Resources/
	@cp -R Tweaks/iSponsorBlock/layout/Library/Application\ Support/iSponsorBlock.bundle Resources/
	@cp -R Tweaks/YTVideoOverlay/layout/Library/Application\ Support/YTVideoOverlay.bundle Resources/
	@cp -R Tweaks/YouQuality/layout/Library/Application\ Support/YouQuality.bundle Resources/
	@cp -R lang/YTLitePlus.bundle Resources/
	@echo -e "==> \033[1mChanging the installation path of dylibs...\033[0m"
	@cp Resources/libcolorpicker.dylib .
	@ldid -r libcolorpicker.dylib
	@install_name_tool -id @rpath/libcolorpicker.dylib libcolorpicker.dylib
	@for dylib in .theos/obj/*.dylib libcolorpicker.dylib; do \
		ldid -r "$$dylib"; \
		install_name_tool -change /usr/lib/libcolorpicker.dylib @rpath/libcolorpicker.dylib "$$dylib"; \
		install_name_tool -change /Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate @rpath/CydiaSubstrate.framework/CydiaSubstrate "$$dylib"; \
		install_name_tool -change /Library/Frameworks/Alderis.framework/Alderis @rpath/Alderis.framework/Alderis "$$dylib"; \
	done
	
