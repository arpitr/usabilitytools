<?php

/**
 * @file
 * Code related to administrative tasks for the Usability Tools module.
 */

/**
 * Provides a Configuration Form for entering the Userability Tools API Key.
 */
function usabilitytools_admin() {
  $form = array();
  $form['usabilitytools_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Usability Tools API Key'),
    '#default_value' => variable_get('usabilitytools_apikey', ''),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t("Enter the UsabilityTools API Key. You can get a Key at http://www.usabilitytools.com."),
    '#required' => TRUE,
  );
  $form['usabilitytools_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Show widget on specific pages'),
    '#default_value' => variable_get('usabilitytools_visibility', USABILITYTOOLS_VISIBILITY_NOTLISTED),
    '#options' => array(
      USABILITYTOOLS_VISIBILITY_NOTLISTED => t('All pages except those listed'),
      USABILITYTOOLS_VISIBILITY_LISTED => t('Only the listed pages'),
    ),
  );
  $form['usabilitytools_paths'] = array(
    '#type' => 'textarea',
    '#title' => '',
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array(
      '%blog' => 'blog',
      '%blog-wildcard' => 'blog/*',
      '%front' => '<front>')
    ),
    '#default_value' => variable_get('usabilitytools_paths', ''),
  );
  $form['usabilitytools_visibility_roles'] = array(
    '#type' => 'radios',
    '#title' => t('Show widget for specific user roles.'),
    '#default_value' => variable_get('usabilitytools_visibility_roles', USABILITYTOOLS_VISIBILITY_ROLE_EXC),
    '#options' => array(
      USABILITYTOOLS_VISIBILITY_ROLE_EXC => t('All roles excpeted selected.'),
      USABILITYTOOLS_VISIBILITY_ROLE_INC => t('Only for selected user role.'),
    ),
  );
  $role_options = array_map('check_plain', user_roles());
  $form['usabilitytools_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#default_value' => variable_get('usabilitytools_roles', array()),
    '#options' => $role_options,
    '#description' => t('If none of the roles are selected, all users will be tracked. If a user has any of the roles checked, that user will be tracked (or excluded, depending on the setting above).'),
  );
  return system_settings_form($form);
}
