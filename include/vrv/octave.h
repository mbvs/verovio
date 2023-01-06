/////////////////////////////////////////////////////////////////////////////
// Name:        octave.h
// Author:      Laurent Pugin
// Created:     2016
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_OCTAVE_H__
#define __VRV_OCTAVE_H__

#include "atts_cmn.h"
#include "atts_shared.h"
#include "controlelement.h"
#include "timeinterface.h"

namespace vrv {

//----------------------------------------------------------------------------
// Octave
//----------------------------------------------------------------------------

/**
 * This class models the MEI <octave> element.
 */
class Octave : public ControlElement,
               public TimeSpanningInterface,
               public AttColor,
               public AttExtender,
               public AttLineRend,
               public AttLineRendBase,
               public AttNNumberLike,
               public AttOctaveDisplacement {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    Octave();
    virtual ~Octave();
    Object *Clone() const override { return new Octave(*this); }
    void Reset() override;
    std::string GetClassName() const override { return "Octave"; }
    ///@}

    /**
     * @name Getter to interfaces
     */
    ///@{
    TimePointInterface *GetTimePointInterface() override { return vrv_cast<TimePointInterface *>(this); }
    const TimePointInterface *GetTimePointInterface() const override
    {
        return vrv_cast<const TimePointInterface *>(this);
    }
    TimeSpanningInterface *GetTimeSpanningInterface() override { return vrv_cast<TimeSpanningInterface *>(this); }
    const TimeSpanningInterface *GetTimeSpanningInterface() const override
    {
        return vrv_cast<const TimeSpanningInterface *>(this);
    }
    ///@}

    /**
     * Store the horizontal extender line coordinates
     */
    ///@{
    void ResetDrawingExtenderX();
    void SetDrawingExtenderX(int left, int right);
    ///@}

    /**
     * Get the SMuFL glyph.
     */
    char32_t GetOctaveGlyph(bool withAltaBassa) const;

    /**
     * Calculate the octave line width.
     */
    int GetLineWidth(const Doc *doc, int unit) const;

    /**
     * Determine the vertical content boundary closest to the staff.
     * For refined layout this can take the overlapping bbox into account.
     * Returns a pair consisting of the boundary and a flag indicating whether refined layout was used.
     */
    std::pair<int, bool> GetStaffSideContentBoundary(const Doc *doc, const StaffAlignment *staffAlignment,
        const BoundingBox *horizOverlappingBBox, data_STAFFREL drawingPlace) const override;

    //----------//
    // Functors //
    //----------//

    /**
     * See Object::ResetVerticalAlignment
     */
    int ResetVerticalAlignment(FunctorParams *functorParams) override;

protected:
    //
private:
    //
public:
    //
private:
    /**
     * The X coordinates of the drawn horizontal extender line
     */
    ///@{
    int m_drawingExtenderLeft;
    int m_drawingExtenderRight;
    ///@}
};

} // namespace vrv

#endif
