/////////////////////////////////////////////////////////////////////////////
// Name:        tabgrp.cpp
// Author:      Laurent Pugin
// Created:     2019
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "tabgrp.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "editorial.h"
#include "note.h"
#include "tabrhythm.h"

namespace vrv {

//----------------------------------------------------------------------------
// TabGrp
//----------------------------------------------------------------------------

static ClassRegistrar<TabGrp> s_factory("tabGrp");

TabGrp::TabGrp() : LayerElement("tabgrp-"), DurationInterface()
{
    RegisterInterface(DurationInterface::GetAttClasses(), DurationInterface::IsInterface());

    Reset();
}

TabGrp::~TabGrp() {}

void TabGrp::Reset()
{
    LayerElement::Reset();
    DurationInterface::Reset();
}

bool TabGrp::IsSupportedChild(Object *child)
{
    if (child->Is(NOTE)) {
        assert(dynamic_cast<Note *>(child));
    }
    else if (child->Is(TABRHYTHM)) {
        assert(dynamic_cast<TabRhythm *>(child));
    }
    else if (child->IsEditorialElement()) {
        assert(dynamic_cast<EditorialElement *>(child));
    }
    else {
        return false;
    }
    return true;
}

} // namespace vrv
