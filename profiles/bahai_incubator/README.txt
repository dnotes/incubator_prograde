// $Id$

The Local Baha'i Community Website Incubator is a Drupal installation profile
incorporating many features that would be commonly used on a website for a local
Baha'i community or a group of communities, including news, events, blogs, 
facilities and localities, map and social media integration, and user-submitted 
content.


INSTALLATION AND SETUP
======================

Follow the instructions in the INSTALL.txt file.


USAGE AND EXTENSION
===================

Once you complete the installation and setup, your website should function much
the same as any other Drupal website, and for the most part you should be able
to configure it as you see fit.

The Incubator has modular functionality which can be enabled or disabled from 
the "Modules" administrative menu; e.g. enabling the "Localities" module will
add support for multiple local communities or neighborhoods to your site.

You can add modules or themes to the site as you would any other Drupal site,
keeping in mind that if you wish to upgrade your Incubator installation later,
you may have to keep track of what you added.  One good way to do this is to
add custom themes, for example, to your "sites/[your-site.com]/themes" folder.


UPGRADING
=========

The incubator project has moved to Drupal 7. Owing to the very, very small
number of sites using the Drupal 6 version, there will be no upgrade path.

If you are running the Incubator on an Aegir system, you should be able to 
simply create a new platform using the Incubator profile and then migrate
your site according to standard Aegir migration.

If you are not using Aegir, there are many ways to upgrade.  Here's one:

  1. Make a backup of your database.
  2. Re-download the entire install profile to a new location.
  3. Put the site into maintenance mode.
  4. Copy your sites folder to the new install profile location.
  5. Switch the virtualhost over to the new install profile location.
  6. Run the upgrade.php script.
  7. Check out the site.
  8. Take the site out of maintenance mode.

HELP AND SUPPORT
================

In this early release, there is not much specific help for the Incubator.  If
you run into problems, we suggest the following course of action:

1. Try to search for your problem on google or on drupal.org; in many cases,
   problems of a general nature have already been solved by others.

2. Search the issues at http://drupal.org/project/issues/bahai_incubator (the
   issue queue for the Incubator project) and see if the problem is mentioned.

3. If you can't find your problem in the issue queue, please post a new issue.
   This will help us to improve the Incubator for everyone.
