/* 
 * Copyright (c) 2011, 2014, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import "MColoredView.h"


@implementation MColoredView

- (instancetype) initWithFrame:(NSRect)frameRect
{
  self = [super initWithFrame: frameRect];
  if (self)
  {
    mColor = [[NSColor colorWithDeviceWhite: 232/255.0 alpha: 1.0] retain];
  }
  return self;
}

- (void) dealloc
{
  [mColor release];
  [super dealloc];
}

- (NSColor*)backgroundColor
{
  return mColor;
}

- (void)setBackgroundColor:(NSColor*)color
{
  [mColor autorelease];
  mColor = [color retain];
}

- (void) drawRect:(NSRect)rect
{
  if (!mColor)
  {
    mColor = [[NSColor colorWithDeviceWhite: 232/255.0 alpha: 1.0] retain];
  }
  [mColor set];
  NSRectFill(rect);
}

@end
