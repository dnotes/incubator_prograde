; $Id$

core = 7.22
api = 2

projects[ctools] = 1.3

projects[token] = 1.5
projects[pathauto] = 1.2
projects[transliteration] = 3.1
projects[admin_menu] = 3.0-rc4
projects[admin_alert] = 1.0-alpha4
projects[masquerade] = 1.0-rc5
projects[sudo] = 1.0
projects[css_injector] = 1.8
projects[libraries] = 2.1
projects[mollom] = 2.6
projects[google_analytics] = 1.3
projects[backup_migrate] = 2.7
projects[robotstxt] = 1.1
projects[entity] = 1.1
projects[rules] = 2.3

projects[redirect][version] = 1.0-rc1
projects[redirect][patch][] = "http://drupal.org/files/redirect-detect_prevent_circular_redirects_patch_and_test-1796596-48.patch"

; Do not update noggin without checking noggin_incubator module
projects[noggin] = 1.1

;dev versions do not yet work with our aegir-specific hosts
;projects[nodeformcols][type] = module
;projects[nodeformcols][download][type] = git
;projects[nodeformcols][download][revision] = 0120682a82fa03d7387cc215ab0cce6d3ae96a45
;projects[nodeformcols][download][branch] = 7.x-1.x

projects[l10n_update] = 1.0-beta3
projects[languageicons] = 1.0
projects[potx] = 1.0
projects[l10n_client] = 1.2
projects[i18n] = 1.8
projects[variable] = 2.2
projects[translation_overview] = 2.0-beta1
projects[translation_table] = 1.0-beta1

projects[diff] = 3.2

projects[references] = 2.1
projects[field_group] = 1.1

projects[media] = 1.3
projects[media_youtube] = 1.0-beta3
projects[media_vimeo] = 1.0-beta5
projects[mediaelement] = 1.2
projects[colorbox] = 1.6
projects[plup] = 1.0-alpha1
projects[imagecache_actions] = 1.3

projects[location] = 3.0-rc1
projects[location_chooser] = 1.2
projects[openlayers] = 2.0-beta7
projects[geophp] = 1.7
projects[proj4js] = 1.2

projects[date] = 2.6
projects[date_repeat_instance] = 1.2
projects[fullcalendar] = 2.0
projects[colors] = 1.0-rc1

projects[views] = 3.7
projects[views_date_format_sql] = 3.1
projects[views_slideshow] = 3.0

projects[realname] = 1.1
projects[wysiwyg] = 2.2

projects[skinr] = 2.0-beta1
projects[skinr_lite] = 1.0-alpha3

projects[workbench] = 1.2
projects[workbench_access] = 1.2
projects[workbench_moderation] = 1.3

projects[private] = 1.1

projects[hybridauth] = 2.7

; UNUSED in core incubator

projects[webform] = 3.19
projects[flag] = 2.1
projects[votingapi] = 2.11
projects[fivestar] = 2.0-alpha2
projects[typogrify] = 1.0-rc6
projects[markdown] = 1.1

; Themes
projects[omega][version] = 3.1
projects[zen][version] = 5.1

; Libraries

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.1/ckeditor_3.6.1.tar.gz"
libraries[ckeditor][directory_name] = "ckeditor"

libraries[colorbox][download][type] = "file"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/archive/1.x.zip"
libraries[colorbox][directory_name] = "colorbox"

libraries[fullcalendar][download][type] = "file"
libraries[fullcalendar][download][url] = "http://arshaw.com/fullcalendar/downloads/fullcalendar-1.5.4.zip"

libraries[jquery_cycle][download][type] = "file"
libraries[jquery_cycle][download][url] = "https://raw.github.com/malsup/cycle/master/jquery.cycle.all.js"
libraries[jquery_cycle][download][filename] = "jquery.cycle.all.min.js"
libraries[jquery_cycle][directory_name] = "jquery.cycle"

libraries[plupload][download][type] = "file"
libraries[plupload][download][url] = "https://github.com/downloads/moxiecode/plupload/plupload_1_5_4.zip"
libraries[plupload][directory_name] = "plupload"

;MediaElement is unused in current setup, and is not yet on the library whitelist
;libraries[mediaelement][download][type] = "zip"
;libraries[mediaelement][download][url] = "https://github.com/johndyer/mediaelement/zipball/master"
;libraries[mediaelement][directory_name] = "mediaelement"
