//     ____   ______ __
//    / __ \ / ____// /
//   / /_/ // /    / /
//  / ____// /___ / /___   PixInsight Class Library
// /_/     \____//_____/   PCL 02.01.03.0819
// ----------------------------------------------------------------------------
// Standard ColorSpaces Process Module Version 01.01.00.0307
// ----------------------------------------------------------------------------
// SplitRGBChannelsAction.cpp - Released 2017-04-14T23:07:12Z
// ----------------------------------------------------------------------------
// This file is part of the standard ColorSpaces PixInsight module.
//
// Copyright (c) 2003-2017 Pleiades Astrophoto S.L. All Rights Reserved.
//
// Redistribution and use in both source and binary forms, with or without
// modification, is permitted provided that the following conditions are met:
//
// 1. All redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
// 2. All redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// 3. Neither the names "PixInsight" and "Pleiades Astrophoto", nor the names
//    of their contributors, may be used to endorse or promote products derived
//    from this software without specific prior written permission. For written
//    permission, please contact info@pixinsight.com.
//
// 4. All products derived from this software, in any form whatsoever, must
//    reproduce the following acknowledgment in the end-user documentation
//    and/or other materials provided with the product:
//
//    "This product is based on software from the PixInsight project, developed
//    by Pleiades Astrophoto and its contributors (http://pixinsight.com/)."
//
//    Alternatively, if that is where third-party acknowledgments normally
//    appear, this acknowledgment must be reproduced in the product itself.
//
// THIS SOFTWARE IS PROVIDED BY PLEIADES ASTROPHOTO AND ITS CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PLEIADES ASTROPHOTO OR ITS
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, BUSINESS
// INTERRUPTION; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; AND LOSS OF USE,
// DATA OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ----------------------------------------------------------------------------

#include "SplitRGBChannelsAction.h"
#include "ChannelExtractionProcess.h"
#include "ChannelExtractionInstance.h"
#include "ChannelParameters.h"

#include <pcl/KeyCodes.h>
#include <pcl/ButtonCodes.h>

namespace pcl
{

// ----------------------------------------------------------------------------

#include "SplitRGBChannelsActionIcon.xpm"
#include "ExtractRedChannelActionIcon.xpm"
#include "ExtractGreenChannelActionIcon.xpm"
#include "ExtractBlueChannelActionIcon.xpm"

// ----------------------------------------------------------------------------

SplitRGBChannelsAction::SplitRGBChannelsAction() :
Action( L"Image > Extract > Split RGB Channels", Bitmap( SplitRGBChannelsActionIcon_XPM ), L"Image" )
{
   SetToolTip( "Split RGB Channels" );
}

void SplitRGBChannelsAction::Execute()
{
   ChannelExtractionInstance instance( TheChannelExtractionProcess );

   instance.colorSpace = ColorSpaceId::RGB;
   instance.channelEnabled[0] = true;
   instance.channelEnabled[1] = true;
   instance.channelEnabled[2] = true;

   instance.LaunchOnCurrentView();
}

bool SplitRGBChannelsAction::IsEnabled( ActionInfo info ) const
{
   return info.isImage && info.isColor;
}

// ----------------------------------------------------------------------------

ExtractRedChannelAction::ExtractRedChannelAction() :
Action( L"Image > Extract > Red Channel", Bitmap( ExtractRedChannelActionIcon_XPM ) )
{
   SetToolTip( "Extract Red Channel" );
}

void ExtractRedChannelAction::Execute()
{
   ChannelExtractionInstance instance( TheChannelExtractionProcess );

   instance.colorSpace = ColorSpaceId::RGB;
   instance.channelEnabled[0] = true;
   instance.channelEnabled[1] = false;
   instance.channelEnabled[2] = false;

   instance.LaunchOnCurrentView();
}

bool ExtractRedChannelAction::IsEnabled( ActionInfo info ) const
{
   return info.isImage && info.isColor;
}

// ----------------------------------------------------------------------------

ExtractGreenChannelAction::ExtractGreenChannelAction() :
Action( L"Image > Extract > Green Channel", Bitmap( ExtractGreenChannelActionIcon_XPM ) )
{
   SetToolTip( "Extract Green Channel" );
}

void ExtractGreenChannelAction::Execute()
{
   ChannelExtractionInstance instance( TheChannelExtractionProcess );

   instance.colorSpace = ColorSpaceId::RGB;
   instance.channelEnabled[0] = false;
   instance.channelEnabled[1] = true;
   instance.channelEnabled[2] = false;

   instance.LaunchOnCurrentView();
}

bool ExtractGreenChannelAction::IsEnabled( ActionInfo info ) const
{
   return info.isImage && info.isColor;
}

// ----------------------------------------------------------------------------

ExtractBlueChannelAction::ExtractBlueChannelAction() :
Action( L"Image > Extract > Blue Channel", Bitmap( ExtractBlueChannelActionIcon_XPM ) )
{
   SetToolTip( "Extract Blue Channel" );
}

void ExtractBlueChannelAction::Execute()
{
   ChannelExtractionInstance instance( TheChannelExtractionProcess );

   instance.colorSpace = ColorSpaceId::RGB;
   instance.channelEnabled[0] = false;
   instance.channelEnabled[1] = false;
   instance.channelEnabled[2] = true;

   instance.LaunchOnCurrentView();
}

bool ExtractBlueChannelAction::IsEnabled( ActionInfo info ) const
{
   return info.isImage && info.isColor;
}

// ----------------------------------------------------------------------------

} // pcl

// ----------------------------------------------------------------------------
// EOF SplitRGBChannelsAction.cpp - Released 2017-04-14T23:07:12Z
