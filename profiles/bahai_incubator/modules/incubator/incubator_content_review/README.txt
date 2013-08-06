
INTRODUCTION
============

This module sets up the Workbench suite for use with the Incubator.  It makes
the "editor" role responsible for moderating and publishing all content on the
site, while all other roles with permissions to create content are considered
author roles in this documentation and in the code.


TRANSITIONS
===========

The following transitions are envisioned for common usage:

Transition                 |   Author   |   Editor   |
------------------------------------------------------
draft -> needs_review      |    YES     |    YES     |
draft -> published         |            |    YES     |
needs_review -> draft      |    YES     |    YES     |
needs_review -> published  |            |    YES     |
published -> draft         |    YES     |    YES     |
published -> needs_review  |    YES     |    YES     |


NOTIFICATIONS
=============

Notification emails are sent based on the following interaction rubric:

Transition                 | Revised by |   Author   |  Editor 1  |  Editor 2  |
--------------------------------------------------------------------------------
first draft                |   Author   |            |            |            |
                           |            |            |            |            |
draft -> draft             |   Author   |            |            |            |
draft -> needs_review      |   Author   |            |   notify   |   notify   |
draft -> published (2)     |   Author   |            |   notify   |   notify   |
needs_review -> draft (1)  |   Author   |            |   notify   |   notify   |
needs_rev -> published (2) |   Author   |            |   notify   |   notify   |
published -> draft         |   Author   |            |            |            |
published -> needs_rev (1) |   Author   |            |   notify   |   notify   |
                           |            |            |            |            |
draft -> draft             |  Editor 1  |   notify   |            |            |
draft -> needs_review (1)  |  Editor 1  |   notify   |            |   notify   |
draft -> published (1)     |  Editor 1  |   notify   |            |   notify   |
needs_review -> published  |  Editor 1  |   notify   |            |   notify   |
needs_review -> draft      |  Editor 1  |   notify   |            |   notify   |
published -> draft         |  Editor 1  |   notify   |            |            |
published -> needs_rev (1) |  Editor 1  |   notify   |            |   notify   |

(1) These transitions should rarely happen in common incubator usage.
(2) These transitions can only happen if the author also has the "editor" role.
